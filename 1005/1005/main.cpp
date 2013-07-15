//
//  main.cpp
//  1005
//
//  Created by 王芾 on 13-7-14.
//  Copyright (c) 2013年 王芾. All rights reserved.
//  这题其实只要看懂了题意就非常水了，只有一个技巧点。
//  题目求得其实就是x-y坐标系中某点被吞噬的时间，已知是吞噬以半圆进行每年吞噬50㎡。
//  有x-y坐标之后可求得此点所在半圆面积，在除以吞噬速度就ok了。
//  唯一需要注意的地方在于取值结果，题目要求结果为正整数，所以结果不能四舍五入，需要取不小于结果的整数，从ceil函数即可。
//

#include <iostream>
#include <math.h>
using namespace std;

const double PI = 3.14159;

int main(int argc, const char * argv[])
{
    int iN = 0;
    cin >> iN;
    
    for (int i = 0; i < iN; ++i) {
        double dX, dY;
        cin >> dX >> dY;
        cout << "Property "<< i+1<< ": This property will begin eroding in year "<< ceil(PI * (dX * dX + dY * dY) / 100.0)<< "." << endl;
    }
    
    cout << "END OF OUTPUT." << endl;
    
    return 0;
}

