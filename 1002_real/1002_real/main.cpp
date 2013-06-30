//
//  main.cpp
//  1002_real
//
//  Created by 王芾 on 13-6-30.
//  Copyright (c) 2013年 王芾. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

static map<char,char> map_Transfer;
static map<string, int> map_StandardTelAndCount;

void initMap_Transfer()
{
    for (char c = '0'; c <= '9'; ++c) {
        map_Transfer[c] = c;
    }

    for (char c = 'A'; c <= 'C'; ++c) {
        map_Transfer[c] = '2';
    }
    
    for (char c = 'D'; c <= 'F'; ++c) {
        map_Transfer[c] = '3';
    }
    
    for (char c = 'G'; c <= 'I'; ++c) {
        map_Transfer[c] = '4';
    }
    
    for (char c = 'J'; c <= 'L'; ++c) {
        map_Transfer[c] = '5';
    }
    
    for (char c = 'M'; c <= 'O'; ++c) {
        map_Transfer[c] = '6';
    }
    for (char c = 'P'; c <= 'S'; ++c) {
        map_Transfer[c] = '7';
    }
    for (char c = 'T'; c <= 'V'; ++c) {
        map_Transfer[c] = '8';
    }
    for (char c = 'W'; c <= 'Y'; ++c) {
        map_Transfer[c] = '9';
    }
}

string getStandardFormTel(const string strInput)
{
    string strOutput = "";
    string::const_iterator it = strInput.begin();
    for (int i = 0; it != strInput.end(); ++it) {
        if (*it == '-') {
            continue;
        }
        
        if (i == 3) {
            strOutput.append(1,'-');
        }
        
        strOutput.append(1, map_Transfer[*it]);
        ++i;
    }
    
    return strOutput;
}

int main(int argc, const char * argv[])
{
    int iN = 0;
    string strInput;
    bool bNoDuplicates = true;
    
    initMap_Transfer();
    
    cin >> iN;
    for (int i = 0; i < iN; ++i) {
        strInput.clear();
        cin >> strInput;
        
        strInput = getStandardFormTel(strInput);
        ++map_StandardTelAndCount[strInput];
    }
    
    map<string, int>::iterator it = map_StandardTelAndCount.begin();
    for (; it != map_StandardTelAndCount.end(); ++it) {
        if (it->second > 1) {
            cout << it->first << " " << it->second << endl;
            bNoDuplicates = false;
        }
    }
    
    if (bNoDuplicates) {
        cout << "No duplicates." << endl;
    }
    return 0;
}

