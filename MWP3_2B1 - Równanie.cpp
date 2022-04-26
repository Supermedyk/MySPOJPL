#include <bits/stdc++.h>

using namespace std;



int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> leftSide;
    vector<int> rightSide;
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        leftSide.clear();
        rightSide.clear();
        char atStart = '+';
        char buff;
        bool isX = false;
        bool beforeEqual = true;
        int num = 0;
        while(cin >> noskipws >> buff)
        {
            if (buff == '\n')
            {
                if (isX == true)
                {
                    if (beforeEqual == true)
                    {
                        if (atStart == '+')
                        {
                            rightSide.push_back(num*-1);
                        }
                        else
                        {
                            rightSide.push_back(num);
                        }
                    }
                    else
                    {
                        if (atStart == '+')
                        {
                            rightSide.push_back(num);
                        }
                        else
                        {
                            rightSide.push_back(num*-1);
                        }
                    }
                }
                else
                {
                    if (beforeEqual == true)
                    {
                        if (atStart == '+')
                        {
                            leftSide.push_back(num);
                        }
                        else
                        {
                            leftSide.push_back(num*-1);
                        }
                    }
                    else
                    {
                        if (atStart == '+')
                        {
                            leftSide.push_back(num*-1);
                        }
                        else
                        {
                            leftSide.push_back(num);
                        }
                    }
                }
                break;
            }
            else if (buff == '=')
            {
                if (isX == true)
                {
                    if (atStart == '+')
                    {
                        rightSide.push_back(num*-1);
                    }
                    else
                    {
                        rightSide.push_back(num);
                    }
                }
                else
                {
                    if (atStart == '+')
                    {
                        leftSide.push_back(num);
                    }
                    else
                    {
                        leftSide.push_back(num*-1);
                    }
                }
                atStart = '+';
                num = 0;
                isX = false;
                beforeEqual = false;
            }
            else if (buff == '+')
            {
                if (isX == true)
                {
                    if (beforeEqual == true)
                    {
                        if (atStart == '+')
                        {
                            rightSide.push_back(num*-1);
                        }
                        else
                        {
                            rightSide.push_back(num);
                        }
                    }
                    else
                    {
                        if (atStart == '+')
                        {
                            rightSide.push_back(num);
                        }
                        else
                        {
                            rightSide.push_back(num*-1);
                        }
                    }
                }
                else
                {
                    if (beforeEqual == true)
                    {
                        if (atStart == '+')
                        {
                            leftSide.push_back(num);
                        }
                        else
                        {
                            leftSide.push_back(num*-1);
                        }
                    }
                    else
                    {
                        if (atStart == '+')
                        {
                            leftSide.push_back(num*-1);
                        }
                        else
                        {
                            leftSide.push_back(num);
                        }
                    }
                }
                atStart = '+';
                num = 0;
                isX = false;
            }
            else if (buff == 'x')
            {
                isX = true;
                if (num == 0)
                {
                    num = 1;
                }
            }
            else if (buff == '-')
            {
                if (isX == true)
                {
                    if (beforeEqual == true)
                    {
                        if (atStart == '+')
                        {
                            rightSide.push_back(num*-1);
                        }
                        else
                        {
                            rightSide.push_back(num);
                        }
                    }
                    else
                    {
                        if (atStart == '+')
                        {
                            rightSide.push_back(num);
                        }
                        else
                        {
                            rightSide.push_back(num*-1);
                        }
                    }
                }
                else
                {
                    if (beforeEqual == true)
                    {
                        if (atStart == '+')
                        {
                            leftSide.push_back(num);
                        }
                        else
                        {
                            leftSide.push_back(num*-1);
                        }
                    }
                    else
                    {
                        if (atStart == '+')
                        {
                            leftSide.push_back(num*-1);
                        }
                        else
                        {
                            leftSide.push_back(num);
                        }
                    }
                }
                atStart = '-';
                num = 0;
                isX = false;
            }
            else
            {
                num*=10;
                num += buff-'0';
            }
        }
        int rightANS = 0;
        for (auto i: rightSide)
        {
            rightANS += i;
        }
        int leftANS = 0;
        for (auto i: leftSide)
        {
            leftANS += i;
        }
        if (rightANS == 0)
        {
            cout << "NIE\n";
        }
        else
        {
            if (rightANS < 0)
            {
                rightANS*=-1;
                leftANS*=-1;
            }
            if (rightANS != 1)
            {
                leftANS /= rightANS;
                rightANS /= rightANS;
            }
            cout << leftANS << "\n";
        }
    }
}
