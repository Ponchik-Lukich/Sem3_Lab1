#ifndef LAB1_FUNCTION_H
#define LAB1_FUNCTION_H

#include "Sequence.h"

using namespace std;

template <class T>
int compareT(T a, T b)
{
    if (a < b)
    {
        return 0;
    }
    if (a > b)
    {
        return 1;
    }
    return 2;
//    return a <= b;
}

#endif
