//
//  main.cpp
//  1003
//
//  Created by 王芾 on 13-7-1.
//  Copyright (c) 2013年 王芾. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

double getCardsLength(int n)
{
    if (n < 1) {
        return -1;
    }
    double dResult = 0.0;
    for (int i = 0; i < n; ++i) {
        dResult += 1.0 / (i+2);
    }
    
    return dResult;
}

int binary_search(int low, int high, double key)
{
    int mid = (low + high)/2;
    if (low > high) {
        return  -1;
    }
    else
    {
        bool bigger = getCardsLength(mid) >= key;
        bool beforeless = getCardsLength(mid - 1) < key;
        if (bigger && beforeless) {
            return mid;
        }
        else if (!bigger)
        {
            return binary_search(mid + 1, high, key);
        }
        else
        {
            return binary_search(low, mid - 1, key);
        }
    }
}

int main(int argc, const char * argv[])
{

    double dInput = 0.00;
    
    while (cin >> dInput) {
        if (0.00 == dInput) {
            break;
        }
        
        cout << binary_search(1, 276, dInput) << " card(s)"<< endl;
    }
    return 0;
}

