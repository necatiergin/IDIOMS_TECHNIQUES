#include <type_traits>
#include <utility>

// ---- ScopeGuard (minimal, no move members) ---------------------------------
//  - Calls the stored callable when leaving scope (RAII).
//  - Has release() to cancel the cleanup.
//  - Non-copyable; move members are intentionally not provided.
// ----------------------------------------------------------------------------

template<class F>
class ScopeGuard {
public:
    // Store by value; decay through the helper (see make_scope_guard below).
    explicit ScopeGuard(F f) noexcept(std::is_nothrow_move_constructible_v<F>)
        : func_(std::move(f)), active_(true) {    }

    // Non-copyable: avoid double cleanup
    ScopeGuard(const ScopeGuard&) = delete;
    ScopeGuard& operator=(const ScopeGuard&) = delete;

    // No move members are declared (kept intentionally simple).

    ~ScopeGuard() noexcept 
    {
        if (active_) {
            // Never let exceptions escape a destructor-like path
            try { func_(); }
            catch (...) {}
        }
    }

    // Cancel the cleanup (e.g., when ownership is transferred elsewhere)
    void release() noexcept 
    {
        active_ = false; 
    }

private:
    F    func_;
    bool active_;
};

// Helper to deduce and decay F cleanly
template<class F>
auto make_scope_guard(F&& f) 
{
    using Fn = std::decay_t<F>;
    return ScopeGuard<Fn>(std::forward<F>(f));
}


#include <new>      // std::nothrow
#include <iostream> // (only if you want to print in stubs)

// --- Resource classes (mock) ------------------------------------------------
class ResourceX { /* ... */ };
class ResourceY { /* ... */ };

struct ResourceZ {
    bool is_valid;
};

// --- Resource API (ref-based for clarity) -----------------------------------
ResourceX* acquire_x();            // returns new’d pointer or nullptr on failure
void       free_x(ResourceX*);

void init_y(ResourceY&);
void free_y(ResourceY&);
bool is_valid(const ResourceY&);

void init_z(ResourceZ&);
void free_z(ResourceZ&);

// --- Simple stubs for demo ---------------------------------------------------
ResourceX* acquire_x() 
{ 
    return new (std::nothrow) ResourceX{}; 
}

void free_x(ResourceX* p) 
{ 
    delete p; 
}

void init_y(ResourceY&) { /* ... */ }
void free_y(ResourceY&) { /* ... */ }

bool is_valid(const ResourceY&)
{
    return true; 
} // flip to false to test early-return

void init_z(ResourceZ& z) 
{
    z.is_valid = true;
} // flip to false to test early-return

void free_z(ResourceZ&) { /* ... */ }

// --- Function using ScopeGuard ----------------------------------------------
bool do_something()
{
    // Acquire X
    ResourceX* x_ptr = acquire_x();
    if (!x_ptr)
        return false;

    // One line, one responsibility: free X when scope ends
    auto x_guard = make_scope_guard([&]() noexcept { free_x(x_ptr); });

    // Prepare and validate Y
    ResourceY y;
    init_y(y);
    if (!is_valid(y))
        return false;   // X is freed automatically

    // Tie Y to scope
    auto y_guard = make_scope_guard([&]() noexcept { free_y(y); });

    // Prepare and validate Z
    ResourceZ z{};
    init_z(z);
    auto z_guard = make_scope_guard([&]() noexcept { free_z(z); });

    if (!z.is_valid)
        return false;   // X, Y, Z are all cleaned up (LIFO)

    // ... real work here ...
    // If you hand off a resource, you can cancel its cleanup:
    // x_guard.release(); // after transferring ownership of x_ptr

    return true; // On exit, Z -> Y -> X cleanups run in reverse order
}
