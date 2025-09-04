#include <tuple>
#include <iostream>

struct LoggerPolicy {
    void log(const std::string& msg) const {
        std::cout << "[log] " << msg << '\n';
    }
};

struct AuthPolicy {
    void auth(const std::string& user) const {
        std::cout << "[auth] Welcome, " << user << '\n';
    }
};

template <typename... Policies>
class Service {
public:
    Service(Policies... ps) : policies_{std::move(ps)...} {}

    template <typename T>
    T& get_policy() {
        return std::get<T>(policies_);
    }

private:
    std::tuple<Policies...> policies_;
};

// usage
Service svc{ LoggerPolicy{}, AuthPolicy{} };
svc.get_policy<LoggerPolicy>().log("starting");
svc.get_policy<AuthPolicy>().auth("admin");
