#include "function.h"

int factorial(int a)
{
    if(a == 0 || a == 1)
        return 1;
    return a * factorial(a - 1);

}