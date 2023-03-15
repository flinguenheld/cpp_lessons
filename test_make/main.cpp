#include "src/hello.h"
#include "src/random.h"

#include <iostream>


int main (int argc, char *argv[])
{
    SayHello(RandomInt(10));

    return 0;
}
