#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>

#include <stdlib.h>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kEnd};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


// Read the given file to return a vector
vector<vector<State>> ReadBoardFile(const string &path)
{
    vector<vector<State>> board;
    std::ifstream ifs (path);

    string line;
    while (std::getline(ifs, line)) {

        vector<State> v;
        std::istringstream stream(line);
        int i;
        char c;
        // cout << line;
        while (stream >> i >> c && c == ','){
            if (i == 0){
                v.push_back(State::kEmpty);
            } else {
                v.push_back(State::kObstacle);
            }
        }
        board.push_back(v);
    }

    return board;
}

// Print the given board in a such beautiful way
void PrintBoard(const vector<vector<State>> &board)
{
    for (const vector<State>b: board){
        for (const State s: b){

            switch (s) {

                case State::kEmpty:
                    cout << "O  ";
                    break;
                case State::kPath:
                    cout << "🚗 ";
                    break;
                case State::kStart:
                    cout << "🚦 ";
                    break;
                case State::kEnd:
                    cout << "🏁 ";
                    break;
                case State::kClosed:
                    cout << "X  ";
                    break;
                default:
                    cout << "⛰️  ";
                    break;
                }
        }
        cout << "\n";
    }
}

int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open_nodes, vector<vector<State>> &board)
{
    open_nodes.push_back(vector<int>{x, y, g, h});
    board[x][y] = State::kClosed;
}

bool Compare(const vector<int> &a, const vector<int> &b)
{
    return (a[2] + a[3]) > (b[2] + b[3]);
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
    sort(v->begin(), v->end(), Compare);
}

bool CheckValidCell(int x, int y, const vector<vector<State>> &grid)
{
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());

    if (on_grid_x && on_grid_y)
        return grid[x][y] == State::kEmpty;
    return false;
}

/** 
 * Expand current nodes's neighbors and add them to the open list.
 */
void ExpandNeighbors(const vector<int> &current, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid) {
  // Get current node's data.
  int x = current[0];
  int y = current[1];
  int g = current[2];

  // Loop through current node's potential neighbors.
  for (int i = 0; i < 4; i++) {
    int x2 = x + delta[i][0];
    int y2 = y + delta[i][1];

    // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
    if (CheckValidCell(x2, y2, grid)) {
      // Increment g value and add neighbor to open list.
      int g2 = g + 1;
      int h2 = Heuristic(x2, y2, goal[0], goal[1]);
      AddToOpen(x2, y2, g2, h2, openlist, grid);
    }
  }
}

vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2])
{
    vector<vector<int>> open{};

    // Initialize the starting node.
    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0],goal[1]);
    AddToOpen(x, y, g, h, open, grid);

    while (open.size() > 0) {
        // Get the next node
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        x = current[0];
        y = current[1];
        grid[x][y] = State::kPath;

        // Check if we're done.
        if (x == goal[0] && y == goal[1]) {
          grid[init[0]][init[1]] = State::kStart;
          grid[goal[0]][goal[1]] = State::kEnd;
          return grid;
        }
        
        // If we're not done, expand search to current node's neighbors.
        ExpandNeighbors(current, goal, open, grid);
      }

    cout << "No path found!" << "\n";
    return vector<vector<State>>{};
}


// --
int main (int argc, char *argv[])
{
    vector<vector<State>> board;
    board = ReadBoardFile("./file.board");

    int init[2]{0, 0};
    int goal[2]{4, 5};


    auto solution = Search(board, init, goal);
    PrintBoard(solution);

    return 0;
}
