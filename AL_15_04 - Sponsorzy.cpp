#include <bits/stdc++.h>

using namespace std;

unsigned long long fastpow(unsigned long long a, unsigned long long b,unsigned long long d)
{
    unsigned long long sum = 1;
    while(b > 0)
    {
        if (b%2 == 1)
        {
            sum= (sum*a)%d;
        }
        a=(a*a)%d;
        b/=2;
    }
    return sum%d;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        unsigned long long int n,d;
        cin >> n >> d;
        unsigned long long int a,b;
        unsigned long long int sum = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            sum = (fastpow(a,b,d) * sum) % d;
            sum %= d;
        }
        if (sum == 0)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}
