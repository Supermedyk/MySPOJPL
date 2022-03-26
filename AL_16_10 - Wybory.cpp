#include <bits/stdc++.h>

using namespace std;


struct player
{
    char name = 'A';
    long int val = 0;
    long int wins[10] = {0};
    long int sumOfAllWins = 0;
}*tab;

bool cmp(const player &a, const player &b)
{
    if (a.sumOfAllWins != b.sumOfAllWins)
        return a.sumOfAllWins > b.sumOfAllWins;
    else
        return a.name < b.name;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,p;
    int d;
    cin >> d;
    vector<player> can;
    while(d--)
    {
        can.clear();
        cin >> n >> m >> p;
        tab = new player [n];
        for (int i = 0; i < n; i++)
            tab[i].name+=i;
        int vam;
        for (int i = 0; i < p; i++)
        {
            string input;
            cin >> input >> vam;
            for (int i = 0; i < input.length()-1; i++)
            {
                for (int j = i+1; j < input.length(); j++)
                {
                    tab[input[i]-'A'].wins[input[j]-'A']+=vam;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (tab[i].wins[j] > tab[j].wins[i])
                    tab[i].sumOfAllWins++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            can.push_back(tab[i]);
        }
        sort(can.begin(),can.end(),cmp);
        bool pass = true;
        if (n != m)
        {
            if (can[m-1].sumOfAllWins == can[m].sumOfAllWins)
            {
                pass = false;
            }
        }
        if (pass == false)
            cout << "NIE";
        else
            for (int i = 0; i < m; i++)
            {
                cout << can[i].name;
            }
        cout << "\n";
        delete [] tab;
    }
}
