#include "hello.h"

void SayHello(int nb)
{
    for (int i=0; i < nb; ++i){
        std::cout << "Hello" << i << "\n";
    }
}
