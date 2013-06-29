//
//  main.cpp
//  1002---实际是1001
//
//  Created by 王芾 on 13-6-6.
//  Copyright (c) 2013年 王芾. All rights reserved.
//
//  本题取巧，题目要求是5位数字，最高25次幂，因此结果最长是5*25+1（小数点）= 126位
//  因此可定义一变量int iResultArray[126]表示结果
//  主要解题思路是化解R^N 为 R*R*R*R*R......R*R*R*R = N次iResultArray * R。最后计算小数点位置。
//  为方便计算，iResultArray高低位翻转，低位在前。
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int iResultArray[126] = {0};

void timesiResultArraybyR(int R)
{
    for (int i = 0; i < 126; ++i) {
        if (0 == iResultArray[i]) {
            continue;
        }
        iResultArray[i] *= R;
    }
    
    for (int i = 0; i < 126; ++i) {
        if (iResultArray[i] < 10) {
            continue;
        }
        unsigned int iTmp = iResultArray[i];
        iResultArray[i] = iTmp % 10;
        iResultArray[i+1] += iTmp / 10;
    }
}

int main(int argc, const char * argv[])
{
    string strR = "";
    string strN = "";
    int iDotCount = 0;
    int iR = 0;
    int iN = 0;
    bool noDot = false;
    
    while (cin>>strR>>strN) {
        //init iN,iR,iDotCount
        iN = atoi(strN.c_str());
        //if there is no '.'
        if (string::npos == strR.find(".")) {
            iDotCount = 0;
            noDot = true;
        }
        else
        {
            iDotCount = (6 - strR.find(".") - 1) * iN;
            noDot = false;
        }
        
        string strTmp;
        for (int i = 0; i < 6; ++i) {
            if ('.' != strR[i]) {
                strTmp.append(1, strR[i]);
            }
        }
        iR = atoi(strTmp.c_str());
        
        //init iResultArray[]
        for (int i =0; i<126 ; ++i) {
            iResultArray[i] = 0;
        }
        reverse(strTmp.begin(), strTmp.end());
        for (int i = 0; i<strTmp.size(); ++i) {
            iResultArray[i] = strTmp[i] - '0';
        }
        
        //do iResultArray * R for N-1 times
        for (int i =0; i < iN - 1; ++i) {
            timesiResultArraybyR(iR);
        }
        
        //transfer iResultArray to string
        strTmp.clear();
        for (int i =0 ; i < 126 ; ++i) {
            if (!noDot && (i == iDotCount)) {
                strTmp.append(1, '.');
            }
            strTmp.append(1, iResultArray[i] + '0');
        }
        reverse(strTmp.begin(), strTmp.end());
        
        //trim the '0'
        strTmp = strTmp.substr(strTmp.find_first_not_of('0'), strTmp.size());
        strTmp = strTmp.substr(0,strTmp.find_last_not_of('0') + 1);
        //if output is 0
        if (strTmp.empty() || 0 == strTmp.compare(".")) {
            strTmp = "0";
        }
        //trim last '.'
        if (*strTmp.rbegin() == '.') {
            strTmp.erase(strTmp.find('.'));
        }
        cout<< strTmp<< endl;
        
    }
    return 0;
}

