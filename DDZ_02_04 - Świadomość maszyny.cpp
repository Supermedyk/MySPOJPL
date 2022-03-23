#include <bits/stdc++.h>

using namespace std;

int tab[5];
bool ba[100001];

void sito(bool *be, int e)
{
	for (int i=2;i*i<=e;i++)
    {					
    if(!be[i])		
		for (int j=i*i;j<=e;j+=i) 
          be[j] = 1;			
    }
}


int main()
{
    ba[1] = true;
    ba[0] = true;
    sito(ba,100001);
    vector<int> nieparz;
    for (int i = 0; i < 5; i++)
    {
        cin >> tab[i];
        if (tab[i] % 2 == 1 && tab[i] != 5)
        {
            nieparz.push_back(tab[i]);
        }
    }
    if (nieparz.size() == 0)
        cout << "0";
    else
    {
        int buffer;
        int amount = 0;
        for (int i = 0; i <nieparz.size(); i++)
        {
            for (int j = 0; j < 5; j++)
            {
                buffer = 0;
                if (tab[j] == nieparz[i] || tab[j] == 0)
                    continue;
                buffer = tab[j]*10000;
                for (int k = 0; k < 5; k++)
                {
                    buffer = tab[j]*10000;
                    if (tab[k] == tab[j] || tab[k] == nieparz[i])
                        continue;
                    buffer += tab[k]*1000;
                    for (int l = 0; l < 5; l++)
                    {
                        buffer = tab[j]*10000;
                        buffer += tab[k]*1000;
                        if (tab[l] == tab[k] || tab[l] == tab[j] || tab[l] == nieparz[i])
                            continue;
                        buffer+= tab[l]*100;
                        for (int t = 0; t < 5; t++)
                        {
                            buffer = tab[j]*10000;
                            buffer += tab[k]*1000;
                            buffer+= tab[l]*100;
                            if (tab[t] == tab[l] || tab[t] == tab[k] || tab[t] == nieparz[i] || tab[t] == tab[j])
                                continue;
                            buffer += tab[t]*10;
                            buffer += nieparz[i];

                            if (ba[buffer] == false)
                                amount++;
                        }
                    }
                }
            }
        }
        cout << amount << "\n";
    }


}
