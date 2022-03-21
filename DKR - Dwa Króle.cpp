#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    unsigned long long int a,b;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        unsigned long long int sum = a*b;
        unsigned long long int amount = 0;
        if (a < 3 || b < 3)
            {
                if (a <= 2 && b <= 2)
                    amount = 0;
                else
                {
                    if (a == 1 || b == 1)
                    {
                       amount = (max(a,b)-2)*2;
                       if (max(a,b) - 3 == 0)
                       {

                       }
                       else
                       {
                            amount += (max(a,b)-3)*(max(a,b)-2);
                       }
                    }
                    else
                    {
                        amount += ((sum-4)*4);
                        if (amount - 6 == 0)
                        {

                        }
                        else
                        {
                            amount += ((sum-6)*(((a-2)*2)+((b-2)*2)));
                            if (amount - 9 == 0)
                            {

                            }
                            else
                                amount += ((sum-9)*((a-2)*(b-2)));
                        }
                    }
                }
            }
        else
        {

            amount += ((sum-4)*4);
            if (sum-6 <= 0)
            {

            }
            else
            {
                amount += ((sum-6)*(((a-2)*2)+((b-2)*2)));
                if (sum-9 <= 0)
                {

                }
                else
                    amount += ((sum-9)*((a-2)*(b-2)));

            }

        }
        if (amount <= 0)
            cout << "0\n";
        else
            cout << amount << "\n";
    }


}
