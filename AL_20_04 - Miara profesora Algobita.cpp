#include <bits/stdc++.h>
using namespace std;

int tab[1001];

int main()
{
    int d;
    int a;
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> val;
    while(cin >> d >> a)
    {
        memset(tab,0,sizeof tab);
        tab[d] = 1;
        val.clear();
        for (int i = 0; i < a; i++)
        {
            int buff;
            cin >> buff;
            tab[buff] = 1;
            val.push_back(buff);
        }
        val.push_back(d);
        for (int i = val.size()-1; i > 0; i--)
        {
            for (int j = i-1; j > -1; j--)
            {
                tab[val[i]-val[j]] = 1;

            }
        }
        bool pass = true;
        for (int i = 1; i <= d; i++)
        {
            if (tab[i] == 0)
            {
                pass = false;
                break;
            }
        }
        if (pass == true)
            cout << "Tak\n";
        else
            cout << "Nie\n";
    }

}
