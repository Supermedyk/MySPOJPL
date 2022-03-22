#include <bits/stdc++.h>

// FR_10_05 - Pętla
// ULTRA SLOW 

using namespace std;

int tab[300][300];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string in;
    cin >> t;
    set<pair<pair<int,int>,pair<int,int>>> moves;
    while(t--)
    {
        moves.clear();
        memset(tab,0,sizeof tab);
        bool pass = true;
        int x = 150;
        int y = 150;
        tab[x][y] = 1;
        int lastX = x;
        int lastY = y;
        cin >> in;
        for (int i = 0; i < in.length(); i++)
        {
            switch (in[i])
            {
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'S':
                y--;
                break;
            }

            if (tab[x][y] == 1 && moves.find(make_pair(make_pair(x,y),make_pair(lastX,lastY))) == moves.end() && moves.find(make_pair(make_pair(lastX,lastY),make_pair(x,y))) == moves.end())
            {
                pass = false;
                break;
            }
            moves.insert(make_pair(make_pair(x,y),make_pair(lastX,lastY)));
            moves.insert(make_pair(make_pair(lastX,lastY),make_pair(x,y)));
            tab[x][y] = 1;
            lastY = y;
            lastX = x;

        }

        if (pass == false)
            cout << "TAK\n";
        else
            cout << "NIE\n";


    }
}


