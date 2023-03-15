#include "random.h"

int RandomInt(int max)
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int nb = RAND_MAX;
    while (nb >= max) {
        nb = std::rand();
    }

    return nb;

}
