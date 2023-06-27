#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

// ----------------------------------------------------------------------------------------------------
// Mutex used with std::unique_lock -------------------------------------------------------------------
// Thanks to unique_lock, the mutex is automatically released at the end of scope

std::mutex mtx;

void add_and_print(std::shared_ptr<int> val, int nb, int times) {

  for (int i = 0; i < times; ++i) {

    std::unique_lock<std::mutex> ul(mtx); // Add std::defer_lock to unlock on start
    *val += nb;
    std::cout << "Add " << nb << ": " << *val << std::endl;

    ul.unlock(); // Release the sleep
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

int main(int argc, char *argv[]) {
  auto val = std::make_shared<int>(0);

  auto threads = std::vector<std::thread>();
  auto futures = std::vector<std::future<void>>();

  for (int i = 0; i < 1000; ++i) {
    futures.emplace_back(std::async(add_and_print, val, 2, 100));
    threads.emplace_back(std::thread(add_and_print, val, 5, 100));
  }

  for (auto &t : threads) {
    t.join();
  }
  for (auto &f : futures) {
    f.wait();
  }

  return 0;
}
