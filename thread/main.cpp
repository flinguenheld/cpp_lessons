#include <array>
#include <iostream>
#include <numeric>
#include <ostream>
#include <thread>
#include <vector>

#include "vehicle.h"

int main(int argc, char *argv[]) {
  int id = 0; // Define an integer variable
  int sleep_ms = 100;

  auto t1 = std::thread([sleep_ms]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_ms));
    std::cout << "bah ! t1" << std::endl;
  });

  auto t2 = std::thread([sleep_ms]() mutable {
    sleep_ms *= 5;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_ms));
    std::cout << "bah ! t2" << std::endl;
  });

  auto t3 = std::thread(Vehicle(5555));

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
