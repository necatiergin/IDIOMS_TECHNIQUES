#include <vector>
#include <functional>

//swap and iterate pattern

class EventDispatcher {
    
    using callback_t = std::function<void(void)>;

    void defer_event(const callback_t& cb) 
    {
        m_callbacks.emplace_back(cb);
    }

    
    void dispatch_events() 
    {
        std::vector<callback_t> tmp{};
        using std::swap; 
        swap(tmp, m_callbacks);
        for (const auto& callback : tmp) {
            std::invoke(callback);
        }
    }
    
    std::vector<callback_t> m_callbacks;             
};
