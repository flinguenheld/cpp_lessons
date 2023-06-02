#include <iostream>
#include <variant>

class Vehicle {
public:
  Vehicle(int id);
  void operator()();

private:
  int _id;
};
