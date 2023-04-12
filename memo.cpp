#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>

#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <utility>


using std::vector;
using std::cout;
using std::string;

// Ternary operator ---------------------------------
condition ? expression1 : expression2;

// Nested Ternary Operator --------------------------
int number = 0;
string result;
result = (number == 0) ? "Zero" : ((number > 0) ? "Positive" : "Negative");


// ITERATORS ----------------------------------------
std::vector<int> my_vector{1, 5, 15, 6, 3};

for (auto it(my_vector.begin()); it != my_vector.end(); ++it) {
    std::cout << *it << "\n";
}
for (auto it(my_vector.rbegin()); it != my_vector.rend(); ++it) {
    std::cout << *it << "\n";
}

for (auto it(my_vector.cbegin()); it != my_vector.cend(); ++it) { // Constant iterators
    std::cout << *it << "\n";
}

auto vec_it = my_vector.begin();
auto next = std::next(vec_it);
auto prev = std::prev(next);

std::advance(vec_it, 2); // it + 2
std::distance(vec_it, my_vector.end()); // distance !!

// container must implement "insert"
std::copy(my_vector.begin(),
      my_vector.end(),
      std::inserter(my_result1, std::next(my_result1.begin())));


// ALIAS --------------------------------------------
// C Style
typedef std::vector<std::int8_t> ByteVector1;

// C++ Style
using ByteVector2 = std::vector<std::int8_t>;

template <typename T>
using VecOfIntegers = std::vector<T>;


// TUPLE --------------------------------------------
std::tuple<std::int32_t, std::string, float> some_function(
    const std::int32_t input)
{
    return std::make_tuple(input + 1,
                           std::to_string(input + 2),
                           static_cast<float>(input + 3));
}

const auto &[i, s, f] = some_function(42); // Strucutred Binding C++17 : g++ -std=c++17
cout << i << '\n';
cout << s << '\n';
cout << f << '\n';



// FOR LOOPS-----------------------------------------
void PrintBoard(const vector<vector<int>> &board)
{
    // range-based loop
    for (const vector<int>b: board){
        for (const int i: b){
            cout << i;
        }
        cout << "\n";
    }

    for (int i=0; i<board.size(); ++i){
        for (int j=0; j<board[i].size(); ++j){
            cout << board[i][j];
        }
        cout << "\n";
    }
}
// STREAMS - FILE / STRING --------------------------
vector<vector<int>> ReadBoardFile(const string &path)
{
    vector<vector<int>> board;
    std::ifstream ifs (path);

    string line;
    while (std::getline(ifs, line)) {

        vector<int> v;
        std::istringstream stream(line);

        int i;
        char c;
        while (stream >> i >> c && c == ','){
            v.push_back(i);
        }
        board.push_back(v);
    }

    return board;
}

// --------------------------------------------------
int main (int argc, char *argv[])
{

    vector<vector<int>> board {{0, 1, 0, 9, 3, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 0, 0, 0, 1, 0}};

    PrintBoard(board);

    cout << "------------" << "\n";
    cout << std::accumulate(board[0].begin(), board[0].end(), 0) << "\n";

    return 0;
}
