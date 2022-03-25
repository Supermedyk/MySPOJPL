#include <bits/stdc++.h>

using namespace std;

struct ant
{
    int x,y;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int bfv;
    int n = INT_MIN,e = INT_MIN,s = INT_MAX,w = INT_MAX;
    cin >> t;
    vector<ant> photo;
    while(t--)
    {
        photo.clear();
        n = INT_MIN;e = INT_MIN;s = INT_MAX;w = INT_MAX;
        ant bff;
        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            cin >> bff.x >> bff.y >> bfv;
            if (bfv == 1)
            {
                if (bff.x > e)
                {
                    e = bff.x;
                }
                if (bff.x < w)
                {
                    w = bff.x;
                }
                if (bff.y > n)
                {
                    n = bff.y;
                }
                if (bff.y < s)
                {
                    s = bff.y;
                }
            }
            photo.push_back(bff);
        }
        int howMany = 0;
        for (int i = 0; i < photo.size(); i++)
        {
            if ((photo[i].x <= e && photo[i].x >= w) && (photo[i].y <= n && photo[i].y >= s))
                howMany++;
        }
        cout << howMany << "\n";

    }

}
