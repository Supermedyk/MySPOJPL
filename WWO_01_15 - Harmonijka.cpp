#include <bits/stdc++.h>

using namespace std;

int tab[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> tab[i];
    }
    int len = 0;
    int buffLen = 0;
    int howMuch = 1;
    bool Less = false;
    bool powtorka = false;
    for (int i = 1; i < t; i++)
    {
        if (Less == false)
        {
            if (tab[i]-tab[i-1] == howMuch)
            {
                buffLen++;
                Less = true;
                howMuch++;
                powtorka = false;
            }
            else
            {
                if (len < buffLen)
                {
                    len = buffLen;
                }
                buffLen = 0;
                howMuch = 1;
                Less = false;
                if (powtorka == true)
                {
                    powtorka = false;
                }
                else
                {
                    powtorka = true;
                    i--;
                }
            }
        }
        else
        {
            if (tab[i-1]-tab[i] == howMuch)
            {
                buffLen++;
                Less = false;
                howMuch++;
                powtorka = false;
            }
            else
            {
                if (len < buffLen)
                {
                    len = buffLen;
                }
                buffLen = 0;
                howMuch = 1;
                Less = false;
                if (powtorka == true)
                {
                    powtorka = false;
                }
                else
                {
                    powtorka = true;
                    i--;
                }

            }
        }
    }
    if (buffLen > len)
        len = buffLen;
    if (len != 0)
    len++;
    cout << len;
}
