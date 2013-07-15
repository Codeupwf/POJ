//
//  main.cpp
//  1004
//
//  Created by 王芾 on 13-7-14.
//  Copyright (c) 2013年 王芾. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    double dBalance = 0.0;
    double dAllBalance = 0.0;
    
    for (int i = 0; i < 12; ++i) {
        cin >> dBalance;
        dAllBalance += dBalance;
    }
    
    cout << "$" << dAllBalance / 12.0 <<endl;
    
    return 0;
}

