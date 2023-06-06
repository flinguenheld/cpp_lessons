#include <array>
#include <chrono>
#include <iostream>
#include <map>
#include <math.h>
#include <memory>
#include <numeric>
#include <ostream>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

#include <future>

#include "vehicle.h"

// ----------------------------------------------------------------------------------------------------
// Async with a class ---------------------------------------------------------------------------------

class Test {

public:
  Test(std::string message) : _message(message){};
  std::string hello(int time_to_sleep) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep));
    std::cout << "From thread " << std::this_thread::get_id() << ": " << _message << std::endl;
    return "Hello";
  };

private:
  std::string _message;
};

int main(int argc, char *argv[]) {

  auto my_test = Test("Mange ton chien");
  auto future = std::async(&Test::hello, my_test, 2000);
  // future.wait();
  std::cout << "Message from thread: " << future.get() << std::endl;

  return 0;
}

// ----------------------------------------------------------------------------------------------------
// Compare async & deferred ---------------------------------------------------------------------------

// void do_some_stuff(int loops) {
//
//   std::cout << "Func thread id: " << std::this_thread::get_id() << std::endl;
//   for (int i = 0; i < loops; ++i)
//     sqrt(12345.6789);
// }

// int main(int argc, char *argv[]) {
//
//   std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
//
//   auto t1 = std::chrono::high_resolution_clock::now();
//
//   std::vector<std::future<void>> futures;
//   for (int i = 0; i < 10; ++i) {
//     futures.emplace_back(std::async(std::launch::async, do_some_stuff, 1e9));
//     // futures.emplace_back(std::async(std::launch::deferred, do_some_stuff, 1e9));
//   }
//
//   for (auto &f : futures) {
//     f.wait();
//   }
//
//   auto t2 = std::chrono::high_resolution_clock::now();
//
//   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
//   std::cout << "Time used: " << duration << " us" << std::endl;
//   return 0;
// }

// ----------------------------------------------------------------------------------------------------
// Async ----------------------------------------------------------------------------------------------

// float divide_xy(float x, float y) {
//
//   std::cout << "Func thread id: " << std::this_thread::get_id() << std::endl;
//   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//   if (y == 0) {
//     throw std::runtime_error("Division by zero !");
//   }
//   return x / y;
// }
//
// int main(int argc, char *argv[]) {
//
//   std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
//
//   auto future = std::async(std::launch::async, divide_xy, 5, 0);
//
//   try {
//     std::cout << "Result : " << future.get() << std::endl;
//   } catch (std::runtime_error e) {
//     std::cout << e.what() << std::endl;
//   }
//
//   return 0;
// }

// ----------------------------------------------------------------------------------------------------
// Promises and futures -------------------------------------------------------------------------------

// void modifyMessage(std::promise<std::string> &&promise, std::string message, int time) {
//   std::this_thread::sleep_for(std::chrono::milliseconds(time));
//   auto new_message = message + " has been modified " + std::to_string(time);
//   promise.set_value(new_message);
// }
//
// int main(int argc, char *argv[]) {
//
//   auto message = "Hello";
//
//   std::promise<std::string> prms;
//   std::future<std::string> ftr = prms.get_future();
//
//   auto t = std::thread(modifyMessage, std::move(prms), message, 2000);
//
//   auto returned_message = ftr.get();
//   std::cout << "Returned message: " << returned_message << std::endl;
//
//   t.join();
//
//   return 0;
// }
