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
        for (const auto& callback : std::exchange(m_callbacks, {})) {
            std::invoke(callback);
        }
    }
    
    std::vector<callback_t> m_callbacks;             
};
