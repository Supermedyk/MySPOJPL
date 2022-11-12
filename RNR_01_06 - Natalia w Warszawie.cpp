#include <bits/stdc++.h>

using namespace std;

int peselWeights[10] = {1,3,7,9,1,3,7,9,1,3};
int counter = 0;

void countPesels(string PESEL, int index, int sum)
{
    if (index == 10)
    {
        if (PESEL[index] == '?')
        {
            counter++;
            return;
        }
        else
        {
            if (10-(sum%10) == 10 && PESEL[index] == '0')
            {
                counter++;
                return;
            }
            else if (10-(sum%10) == PESEL[index]-'0')
            {
                counter++;
                return;
            }
            else
            {
                return;
            }
        }
    }
    else
    {
        if (PESEL[index] != '?')
        {
            countPesels(PESEL,index+1,sum+(peselWeights[index]*(PESEL[index]-'0')));
        }
        else
        {
            if (index != 9)
            {
                for (int i = 0; i < 10; i+=1)
                {
                    countPesels(PESEL,index+1,sum+(peselWeights[index]*i));
                }
            }
            else
            {
                for (int i = 0; i < 10; i+=2)
                {
                    countPesels(PESEL,index+1,sum+(peselWeights[index]*i));
                }
            }
        }

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    vector<int> questionMarks;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> input;
        input[0] = '1';
        input[1] = '9';
        input[2] = '2';
        input[3] = '2';
        input[4] = '1';
        input[5] = '4';
        for (int i = 0; i< input.length(); i++)
        {
            if (input[i] == '?')
            {
                questionMarks.push_back(i);
            }
        }
        if (questionMarks.size() == 0)
        {
            cout << "1\n";
        }
        else
        {
            counter = 0;
            countPesels(input,0,0);
            cout << counter << "\n";
        }

    }
}
