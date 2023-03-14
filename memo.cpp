#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>

#include <fstream>
#include <iostream>
#include <sstream>

using std::vector;
using std::cout;
using std::string;


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
