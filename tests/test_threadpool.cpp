#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ThreadPool.h"
#include <atomic>
#include <chrono>
#include <thread>

TEST_CASE("Basic task execution", "[ThreadPool]") {
    ThreadPool pool(4);
    std::atomic<int> counter = 0;

    for (int i = 0; i < 10; ++i) {
        pool.submit([&counter]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            counter++;
        });
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    REQUIRE(counter == 10);
}

TEST_CASE("ThreadPool handles mixed task load", "[ThreadPool]") {
    ThreadPool pool(3);
    std::vector<int> results(5);

    for (int i = 0; i < 5; ++i) {
        pool.submit([i, &results]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            results[i] = i * i;
        });
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    REQUIRE(results == std::vector<int>({0, 1, 4, 9, 16}));
}
