#pragma once
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <stdexcept>

using namespace std;

class ThreadPool {
private:
    vector<thread> workers;
    queue<function<void()>> tasks;

    mutex queue_mutex;
    condition_variable condition;
    atomic<bool> stop;

public:
    ThreadPool(size_t threads);
    ~ThreadPool();

    template<class F>
    void submit(F&& f) {
        {
            unique_lock<mutex> lock(queue_mutex);
            if (stop.load()) {
                throw runtime_error("Submit on stopped ThreadPool");
            }
            tasks.emplace(forward<F>(f));
        }
        condition.notify_one();
    }

    void shutdown();
};
