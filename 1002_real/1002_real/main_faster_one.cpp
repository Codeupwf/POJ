#include <iostream>
#include <string>
#include <map>

using namespace std;

int mymap[]= {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main()
{
   
    map<int, int> m_result;

    int iCount = 0;
    cin >> iCount;

    string strNumbers;

    while(iCount--)
    {
        cin >> strNumbers;

        int s = 0;
        for (int j = 0; j < strNumbers.length(); j++)
        {
            if (strNumbers[j] != '-')
            {
                if (strNumbers[j] - '0' < 10)
                {
                   s *= 10;
                   s += strNumbers[j] - '0';
                }
                else
                {
                    s *= 10;
                    s += mymap[strNumbers[j] - 'A'];
                }
            }
        }

        m_result[s]++;
    }
    
    bool flag = false;

    map<int, int>::iterator iter_result = m_result.begin();
    while(iter_result != m_result.end())
    {                                            
        if (1 == iter_result->second)
        {
            iter_result++;
            continue;
        }
        //cout << iter_result->first << " " << iter_result->second << endl;
        printf("%03d-%04d %d\n",(iter_result->first / 10000), (iter_result->first % 10000), iter_result->second);
        iter_result++;
        flag = true;
    }

    if (!flag)
    {
        cout << "No duplicates." << endl;
    }

    return 0;
}