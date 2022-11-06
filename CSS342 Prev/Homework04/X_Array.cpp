//
// Created by Sam Singh on 5/7/22.
//

#include "X_Array.h"

X_Array::X_Array()
{
    dataArray = new int *[1];
    dataArray[0] = new int[10];
    currMax = 10;
    currLength = 0;
}

X_Array