#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    long int x,y,s,m,k;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> s >> m >> k;
        char in;
        bool pass = false;
        int when = 1;
        long int index = 1;
        for (int i = 0; i < k ; i++)
        {
            cin >> in;
            switch (in)
            {
            case 'N':
                if (abs(y+1-m) < abs(y-m))
                {
                    y++;
                }
                break;
            case 'S':
                if (abs(y-1-m) < abs(y-m))
                {
                    y--;
                }
                break;
            case 'W':
                if (abs(x-1-s) < abs(x-s))
                {
                    x--;
                }
                break;
            case 'E':
                if (abs(x+1-s) < abs(x-s))
                {
                    x++;
                }
                break;
            }
            if (s == x && m == y && pass == false)
            {
                pass = true;
                when = index;
            }
            index++;
        }
        if (pass == true)
            cout << when << "\n";
        else
            cout << "NIE\n";
    }
}
