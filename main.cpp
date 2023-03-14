#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


void read(std::ifstream &file){

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
}


int main (int argc, char *argv[])
{
    std::ifstream my_file("board.txt");

    if (my_file){
        read(my_file);
    }

    std::string a = "199.2.3.5.6a";

    std::istringstream my_stream(a);

    char c;
    int n;
    while (my_stream >> n >> c) {
        std::cout << n << c << "\n";
    }


    return 0;
}
