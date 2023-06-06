#include <array>
#include <chrono>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <string>
#include <thread>
#include <vector>

#include "vehicle.h"

// ----------------------------------------------------------------------------------------------------
// Example multiple threads ---------------------------------------------------------------------------

class Something {
public:
  Something(int sleeping_time, std::string name) : _sleeping_time(sleeping_time), _name(name){};

  void launch() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * _sleeping_time));
    std::cout << "Let's go for " << _name << ": " << _sleeping_time * 100 << " ms" << std::endl;
  };

  void done() { std::cout << "Thread " << _name << " done." << std::endl; }

private:
  int _sleeping_time;
  std::string _name;
};

// int main(int argc, char *argv[]) {
//
//   std::map<std::shared_ptr<Something>, std::thread> threads;
//
//   for (int i = 10; i > 1; --i) {
//
//     auto ptr = std::make_shared<Something>(i, "Thread " + std::to_string(i));
//     threads[ptr] = std::thread(&Something::launch, ptr);
//   }
//
//   for (auto &t : threads) {
//
//     t.second.join();
//     t.first->done();
//   }
//
//   return 0;
// }

// ----------------------------------------------------------------------------------------------------
// Example with a specific class method (instead of () ) ----------------------------------------------

// int main(int argc, char *argv[]) {
//
//   auto v1 = std::make_shared<Vehicle>(100);
//
//   auto t1 = std::thread(&Vehicle::up_and_show_id, v1, 5, "Honda", 100);
//   auto t2 = std::thread(&Vehicle::up_and_show_id, v1, 20, "V25", 50);
//
//   t1.join();
//   t2.join();
//
//   return 0;
// }

// ----------------------------------------------------------------------------------------------------
// Example with variatic function ---------------------------------------------------------------------

// void func_for_thread(int sleep_time, std::string &title) {
//
//   title += "hii";
//   std::cout << "    Thread " << title << " launched for " << sleep_time << " ms." << std::endl;
//   std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
//   std::cout << "    Title: " << title << " -> " << &title << std::endl;
//   std::cout << "    Thread " << title << " done." << std::endl;
// }
//
// int main(int argc, char *argv[]) {
//
//   std::string title1 = "pouet";
//   std::string title2 = "hého";
//
//   std::cout << "title1: " << title1 << " -> " << &title1 << std::endl;
//   std::cout << "title2: " << title2 << " -> " << &title2 << std::endl;
//
//   auto t1 = std::thread(func_for_thread, 500, std::ref(title1));
//   auto t2 = std::thread(func_for_thread, 200, std::ref(title2));
//
//   t1.join();
//   t2.join();
//
//   std::cout << "title1: " << title1 << " -> " << &title1 << std::endl;
//   std::cout << "title2: " << title2 << " -> " << &title2 << std::endl;
//
//   return 0;
// }

// ----------------------------------------------------------------------------------------------------
// Example with lambda and class ----------------------------------------------------------------------

// int main(int argc, char *argv[]) {
//   int id = 0; // Define an integer variable
//   int sleep_ms = 100;
//
//   auto t1 = std::thread([sleep_ms]() {
//     std::this_thread::sleep_for(std::chrono::milliseconds(sleep_ms));
//     std::cout << "bah ! t1" << std::endl;
//   });
//
//   auto t2 = std::thread([sleep_ms]() mutable {
//     sleep_ms *= 5;
//     std::this_thread::sleep_for(std::chrono::milliseconds(sleep_ms));
//     std::cout << "bah ! t2" << std::endl;
//   });
//
//   auto t3 = std::thread(Vehicle(5555));
//
//   t1.join();
//   t2.join();
//   t3.join();
//
//   return 0;
// }
