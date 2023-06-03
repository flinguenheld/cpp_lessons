#include <iostream>
#include <variant>

class Vehicle {
public:
  Vehicle(int id);
  void operator()();

  void up_and_show_id(int id, std::string new_name, int sleep_for);

private:
  int _id;
  std::string _name;
};
