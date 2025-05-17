# 🧵 Parallel Task Scheduler

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![License](https://img.shields.io/github/license/Mozeel-V/parallel-task-scheduler)](LICENSE)
[![Tested with Catch2](https://img.shields.io/badge/tested%20with-Catch2-blue)](https://github.com/catchorg/Catch2)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey)]()

A multithreaded task scheduler built in modern C++ to demonstrate concurrency, thread pooling, and synchronization using low-level primitives like `std::thread`, `std::mutex`, and `std::condition_variable`.

---

## 🔍 Overview

This project implements a lightweight thread pool that efficiently distributes and executes independent tasks in parallel. It is ideal for understanding fundamental concurrency patterns in modern systems and how synchronization mechanisms like mutexes and condition variables work together.

The goal is to emulate low-latency task dispatching behavior found in performance-critical systems such as job schedulers, parallel processing frameworks, or backend engines.

---

## 🚀 Features

- 🧵 **Custom Thread Pool** using `std::thread`
- 🔒 **Thread-safe Queue** guarded by `std::mutex` and `std::unique_lock`
- ⏳ **Task Scheduling** with FIFO dispatch and efficient wake/sleep via `std::condition_variable`
- 🧼 **Graceful Shutdown** of worker threads
- ⚙️ Clean modular structure with headers and source files

---

## 📁 Directory Structure

```bash
ParallelTaskScheduler/
│
├── include/
│   └── ThreadPool.h            # Declarations only
│
├── src/
│   ├── main.cpp                # Main test program
│   └── ThreadPool.cpp          # Definitions of ThreadPool methods
│
├── tests/
│   └── test_threadpool.cpp     # Catch2-based unit tests
│
├── Makefile                   # For building
├── LICENSE                    # MIT open source LICENSE
├── directory-structure.txt    # Directory Structure
├── .gitignore                 # For GitHub
└── README.md                  # This File
```

---

## ⚙️ Build Instructions

### 🔧 Prerequisites
- C++17 compatible compiler (GCC/Clang/MSVC)
- CMake (≥ 3.10)

### 🏗️ Build and Run
```bash
git clone https://github.com/your-username/parallel-task-scheduler.git
cd parallel-task-scheduler
mkdir build && cd build
cmake ..
make
./ParallelTaskScheduler
```

---

## 🧪 Sample Output

```cpp
Thread 1 is executing task 1
Thread 3 is executing task 2
Thread 2 is executing task 3
...
```

---

## Run Tests

`catch.hpp` is already included in the `tests/` folder
```bash
make test
```
You should see:
```bash
All tests passed (2 assertions in 2 test cases)
```

---

## 💡 Concepts Demonstrated

| Concept                   | Description                                                   |
| ------------------------- | ------------------------------------------------------------- |
| `std::thread`             | Spawns multiple workers to execute tasks concurrently         |
| `std::mutex`              | Ensures mutual exclusion while accessing shared queue         |
| `std::condition_variable` | Notifies threads when new tasks are available                 |
| RAII                      | Ensures automatic cleanup via destructors for safe shutdown   |
| Concurrency & Parallelism | Core systems programming skill                                |

---

## 📄 License

This project is licensed under the MIT License. See LICENSE for details.

---

### 🤝 Contributions
Feel free to fork, raise issues, or submit PRs to improve this project!

---

## 📝 Author

Mozeel Vanwani | IIT Kharagpur CSE
Email: [vanwani.mozeel@gmail.com]
