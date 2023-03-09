#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
using std::cout;
using std::string;


// For loops
void PrintBoard(const vector<vector<int>> &board)
{
    // range-based loop
    for (const vector<int>i: board){
        for (const int j: i){
            cout << j;
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
