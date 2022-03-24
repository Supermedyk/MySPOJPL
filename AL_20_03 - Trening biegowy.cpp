#include <bits/stdc++.h>

using namespace std;

// AL_20_03 - Trening biegowy

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double buff,bar;
    int whole;
    string in;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> bar >> in;
        buff = (((in[0]-'0')*10+(in[1]-'0'))*3600)+(((in[3]-'0')*10+(in[4]-'0'))*60)+((in[6]-'0')*10+(in[7]-'0'));
        bar/= 1000;
        buff/= bar;
        buff = round(buff);
        whole = buff;
        cout << whole/60 << ":";
        if (whole%60 < 10)
        cout << "0";
        cout << whole%60 << "\n";
    }
}


