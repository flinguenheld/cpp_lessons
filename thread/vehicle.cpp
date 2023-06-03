#include "vehicle.h"
#include <chrono>
#include <thread>

Vehicle::Vehicle(int id) : _id(id) {}

void Vehicle::up_and_show_id(int id, std::string new_name, int sleep_for) {

  std::this_thread::sleep_for(std::chrono::milliseconds(sleep_for));
  _id += id;
  _name += new_name;
  std::cout << "Vehicle " << _name << "; id: " << _id << " has been updated \n";
}

void Vehicle::operator()() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Vehicle object " << _id << " has been created \n";
}
