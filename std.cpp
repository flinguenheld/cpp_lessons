#include <cstdint>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>


// RANDOM -------------------------------------------
std::random_device seed;
auto gen = std::mt19937{seed()};
auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};
auto val = dist(gen);

// CHRONO -------------------------------------------
auto start = std::chrono::steady_clock::now();
auto stop = std::chrono::steady_clock::now();
auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

std::cout << "time : " << elapsed_time.count() << "\n";

auto start = std::chrono::steady_clock::now();
auto stop = std::chrono::steady_clock::now();
std::chrono::duration<float> elapsed_seconds = stop-start;

std::cout << "time : " << elapsed_seconds.count() << "\n";

// LAMBDA -------------------------------------------
auto lamb = [](const auto n){ return n > 0; };

auto fill = [](){static int n; return n++; }; // Same as std::iota
std::generate(my_vector.begin(), my_vector.end(), fill);

std::transform(my_vector.begin(),
           my_vector.end(),
           my_vector.begin(), // It could save in another vector !
           [](const auto val) { return val * 2; });

int total = 0;
total = std::accumulate(my_vector.begin(), my_vector.end(), 16);

// --
std::replace(my_vector.begin(), my_vector.end(), 0, 1000);

std::replace_if(
my_vector.begin(),
my_vector.end(),
[](const auto val) { return val % 2 == 0; },
-1);

// --
std::sort(my_vector.begin(),
      my_vector.end(),
      [](const auto i, const auto j) { return i < j; });

std::sort(my_vector.begin(),
      my_vector.end(),
      [](const auto i, const auto j) { return i > j; });

// --
// Pre C++20
auto remove_it1 = std::remove(my_vector.begin(), my_vector.end(), -1);
my_vector.erase(remove_it1, my_vector.end());

auto remove_it2 = std::remove_if(my_vector.begin(),
                                 my_vector.end(),
                                 [](const auto i) { return i < 0; });
my_vector.erase(remove_it2, my_vector.end());

// Post C++20
std::erase(my_vector, 7);
std::erase_if(my_vector, [](const auto i) { return i < 0; });

// --
const auto min = std::min_element(my_vector.begin(), my_vector.end());
const auto max = std::max_element(my_vector.begin(), my_vector.end());

const auto my_vector2 = std::vector<Data>{{1, 1}, {2, 3}};
const auto my_vector3 = std::vector<Data>{{1, 1}, {2, 2}};
const auto eq = std::equal(std::execution::par,
                           my_vector2.begin(),
                           my_vector2.end(),
                           my_vector3.begin(),
                           [](const auto &i, const auto &j) {
                           return i.v1 < j.v1 && i.v2 < j.v2;
                           });

// --
auto l = [](const auto val) { return (val > -5) && (val < 5); };
const auto check1 = std::all_of(my_vector.begin(), my_vector.end(), l);
const auto check2 = std::any_of(my_vector.begin(), my_vector.end(), l);
const auto check3 = std::none_of(my_vector.begin(), my_vector.end(), l);

// --
const int threshold = 2;
auto fns = std::vector<std::function<bool(const int)>>{
    [&threshold](const int v) { return v > threshold; },
    [&threshold](const int v) { return v < threshold; },
    [&threshold](const int v) { return v == threshold; },
    [&threshold](const int v) { return v != threshold; },
    [&threshold](const int v) { return v >= threshold; },
    [&threshold](const int v) { return v <= threshold; },
};

// auto fns = std::vector<bool (*)(const int)>{
//     [](const int v) { return v > 2; },
//     [](const int v) { return v < 2; },
//     [](const int v) { return v == 2; },
//     [](const int v) { return v != 2; },
//     [](const int v) { return v >= 2; },
//     [](const int v) { return v <= 2; },
// };

for (const auto &fn : fns)
{
    std::cout << std::boolalpha << fn(1) << '\n';
}


