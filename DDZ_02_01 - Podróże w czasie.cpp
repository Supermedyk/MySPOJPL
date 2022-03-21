#include <bits/stdc++.h>

using namespace std;

struct House
{
    double x;
    double y;
    double nr;
    double population;
};


int main()
{
    ios::sync_with_stdio(0);
    vector <double> Nums;
    vector <House> Houses;
    vector <House> Copy;
    cin.tie(NULL);
    int T;
    double Amount;
    double dropX,dropY,dropR;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        Houses.push_back(House());
        cin >> Houses[i].x >> Houses[i].y >> Houses[i].nr >> Houses[i].population;
    }
    Copy = Houses;


    cin >> T;
    for (int i = 0; i < T; i++)
    {
        Amount = 0;
        cin >> dropX >> dropY >> dropR;
        Houses = Copy;
        Copy.clear();
        for (int j = 0; j < Houses.size(); j++)
        {
            if (pow(Houses[j].x-dropX,2)+pow(Houses[j].y-dropY,2) <= pow(dropR,2))
            {
                Amount += Houses[j].population;
                Nums.push_back(Houses[j].nr);
            }
            else
                Copy.push_back(Houses[j]);

        }
        if (Nums.size() != 0)
        {
            for (auto j: Nums)
            {
                cout << j << " ";
            }
            cout << "\n" << Amount << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
        Nums.clear();
    }
}



