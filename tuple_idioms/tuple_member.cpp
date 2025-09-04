#include <tuple>
#include <utility>

template <typename... Args>
class Command {
public:
    Command(Args&&... args)
        : params_(std::forward<Args>(args)...) {
    }

    template <std::size_t I>
    auto& get() 
    {
        return std::get<I>(params_);
    }

private:
    std::tuple<Args...> params_;
};
