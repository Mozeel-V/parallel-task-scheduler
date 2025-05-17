#include "../include/ThreadPool.h"
#include <iostream>

using namespace std;

ThreadPool::ThreadPool(size_t threads) : stop(false) {
    // Creates 'threads' worker threads that run the task processing loop
    for (size_t i = 0; i < threads; ++i) {
        workers.emplace_back([this] {
            while (true) {
                function<void()> task;

                {
                    // Lock the task queue to safely check or pop tasks
                    unique_lock<mutex> lock(this->queue_mutex);

                    // Wait until the thread pool is stopped or a task is available
                    this->condition.wait(lock, [this] {
                        return this->stop.load() || !this->tasks.empty();
                    });

                    // If pool is stopped and no tasks left, exit the worker thread
                    if (this->stop.load() && this->tasks.empty())
                        return;

                    // Get the next task from the queue and remove it
                    task = move(this->tasks.front());
                    this->tasks.pop();
                }

                // Execute the fetched task outside the locked scope
                task();
            }
        });
    }
}

ThreadPool::~ThreadPool() {
    // On destruction, shutdown the pool if not already stopped
    if (!stop.load()) {
        shutdown();
    }
}

void ThreadPool::shutdown() {
    // Signal all threads to stop processing tasks
    stop.store(true);
    condition.notify_all();

    // Join all worker threads to clean up resources safely
    for (thread &worker : workers) {
        if (worker.joinable())
            worker.join();
    }
}
