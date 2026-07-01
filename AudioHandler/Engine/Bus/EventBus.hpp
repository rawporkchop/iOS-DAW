#pragma once

#include <mutex>
#include <queue>

#include "../Event/Events.hpp"

class EventBus {
public:
    void push(Event event)
    {
        std::lock_guard lock(mutex_);
        queue_.push(std::move(event));
    }

    bool pop(Event& event)
    {
        std::lock_guard lock(mutex_);

        if (queue_.empty())
            return false;

        event = std::move(queue_.front());
        queue_.pop();
        return true;
    }

private:
    std::queue<Event> queue_;
    std::mutex mutex_;
};
