#include "../include/ThreadPool.h"
#include <iostream>

using namespace std;

mutex print_mutex;

int main() {
    // Taking user input
    int threadCount, taskCount;
    cout << "Enter number of threads you want in the pool" << endl;
    cin >> threadCount;
    cout << "Enter the number of tasks you want to execute" << endl;
    cin >> taskCount;

    // Simple Input Validation
    if (threadCount <= 0) {
        cerr << "Error: Thread count must be positive." << endl;
        return 1;
    }
    if (taskCount <= 0) {
        cerr << "Error: Task count must be positive." << endl;
        return 1;
    }


    cout << "Starting the thread pool with " << threadCount <<  " threads...\n";
    ThreadPool pool(threadCount);

    // Submit the tasks
    for (int i = 0; i < taskCount; ++i) {
        pool.submit([i]() {
            this_thread::sleep_for(chrono::milliseconds(50));
            lock_guard<mutex> lock(print_mutex);  // Lock before printing
            cout << "Task " << i << " running on thread " 
                 << this_thread::get_id() << endl;
        });
    }

    // this_thread::sleep_for(chrono::milliseconds(1000));
    pool.shutdown();
    cout << "\nAll tasks completed, shutting down the thread pool.\n";
    return 0;
}
