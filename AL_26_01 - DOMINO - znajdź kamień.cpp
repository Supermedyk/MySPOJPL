#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int,int> liczby;
    int t;
    cin >> t;
    while(t--)
    {
        liczby.clear();
        int liczbaPierwsza;
        int liczbaDruga;
        int highest = 0;
        char in;
        for (int i = 0; i < 27; i++)
        {
            cin >> liczbaPierwsza >> in >> liczbaDruga;
            int &b = liczby[liczbaPierwsza];
            b++;
            int &c = liczby[liczbaDruga];
            c++;
            if (b > highest)
            {
                highest = b;
            }
            if (c > highest)
            {
                highest = c;
            }
        }
        int znalezionapierwsza = -1;
        int znalezionadruga = -1;
        for (auto i: liczby)
        {
            if (i.second != highest && znalezionapierwsza == -1)
            {
                znalezionapierwsza = i.first;
            }
            else if (i.second != highest)
            {
                znalezionadruga = i.first;
            }
        }
        if (znalezionadruga == -1)
        {
            znalezionadruga = znalezionapierwsza;
        }
        if (znalezionapierwsza < znalezionadruga)
        {
            int a = znalezionapierwsza;
            znalezionapierwsza = znalezionadruga;
            znalezionadruga = a;
        }
        cout << znalezionadruga << "|" << znalezionapierwsza << "\n";
    }
}
