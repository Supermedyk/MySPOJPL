#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a,b,c;
    double dist = 0;
    double guy;
    cin >> c >> a >> b;
    guy = c;
    a/= 3.6;
    b/= 3.6;
    bool towardsHome = true;
    while(guy > 0)
    {

        if (towardsHome == true)
        {
            dist += guy;
            guy -= (guy/b)*a;
            towardsHome = false;
        }
        else
        {
            dist += (guy/(a+b))*b;
            guy -= (guy/(a+b))*a;
            towardsHome = true;
        }
        if (guy < 0.000001 || (guy/(a+b))*a < 0.000001)
            break;
    }
    cout << setprecision(2)<<fixed<<dist;
}
