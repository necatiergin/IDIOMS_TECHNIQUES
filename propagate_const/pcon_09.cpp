#include <memory>
#include <type_traits>
#include <utility>

template <typename P>
class PropagateConst {
public:
    using element_type = std::remove_pointer_t<
        decltype(std::to_address(std::declval<P&>()))
    >;

    explicit PropagateConst(P ptr)
        noexcept(std::is_nothrow_move_constructible_v<P>)
        : m_ptr{ std::move(ptr) }
    {}

    PropagateConst(const PropagateConst&) = delete;
    PropagateConst& operator=(const PropagateConst&) = delete;

    PropagateConst(PropagateConst&&) = default;
    PropagateConst& operator=(PropagateConst&&) = default;

    element_type* get() noexcept
    {
        return std::to_address(m_ptr);
    }

    const element_type* get() const noexcept
    {
        return std::to_address(m_ptr);
    }

    element_type* operator->() noexcept
    {
        return get();
    }

    const element_type* operator->() const noexcept
    {
        return get();
    }

    element_type& operator*() noexcept
    {
        return *get();
    }

    const element_type& operator*() const noexcept
    {
        return *get();
    }

    explicit operator bool() const noexcept
    {
        return get() != nullptr;
    }

private:
    P m_ptr;
};
