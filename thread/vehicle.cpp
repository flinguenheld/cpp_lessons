#include "vehicle.h"
#include <chrono>
#include <thread>

Vehicle::Vehicle(int id) : _id(id) {}

void Vehicle::operator()() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Vehicle object " << _id << " has been created \n";
}
