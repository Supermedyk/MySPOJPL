#include <bits/stdc++.h>

using namespace std;

char tab[1500][800];

int main()
{
    register int T;
    register int Q;
    register char buff;
    register int d;
    register int dir = 0;
    register deque<int> LastX;
    register deque<int> LastY;
    register int xNow;
    register int yNow;
    scanf("%d",&T);
    while(T--)
    {
        memset( tab,  0/* / sizeof(flags[0][0]) */,tab[0][0] + sizeof(tab)  );
        LastX.clear();
        LastY.clear();
        scanf("%d",&Q);
        d = 0;
        dir = 1;
        xNow = 200;
        yNow = 200;
        LastX.push_back(200);
        LastY.push_back(200);
        buff = getchar_unlocked();
        for (int i = 0; i < Q; i++)
        {
            buff = getchar_unlocked();
            switch(buff)
            {
            case 'L':
                dir--;
                if (dir == -3)
                {
                    dir = 1;
                }
                break;
            case 'R':
                dir++;
                if (dir == 2)
                {
                    dir = -2;
                }
                break;
            }
            switch(dir)
            {
            case 1:
                xNow++;
                break;
            case 0:
                yNow++;
                break;
            case -1:
                xNow--;
                break;
            case -2:
                yNow--;
                break;
            }


            if (buff != 'E')
            {
                tab[LastX.front()][LastY.front()] = 0;
                LastX.pop_front();
                LastY.pop_front();
            }
            if (tab[xNow][yNow] == 1)
            {
                for (int j = i+1; j < Q; j++)
                {
                    buff = getchar_unlocked();
                }
              d = i+1;
              break;
            }
            else
            {
                tab[xNow][yNow] = 1;
                LastX.push_back(xNow);
                LastY.push_back(yNow);
            }

        }
        if (d == 0)
            cout << "TAK\n";
        else
            cout << d << "\n";
        buff = getchar_unlocked();

    }
}
