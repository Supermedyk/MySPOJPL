#include <bits/stdc++.h>

// REALLY SLOW TIME(1.69)

using namespace std;

deque<pair<int,int>> que;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int k;
    cin >> k;
    int buffer;
    int lastElement = -1;
    for (int i = 1; i <= k; i++)
    {
        cin >> buffer;
        if (que.size() == 0)
        {
            que.push_front({buffer,i});
            lastElement = 0;
        }
        else if (buffer > que[0].first)
        {
            que.clear();
            que.push_front({buffer,i});
            lastElement = 0;
        }
        else if (buffer > que[lastElement].first)
        {
            while(que[lastElement].first < buffer)
            {
                que.pop_back();
                lastElement--;
            }
            que.push_back({buffer,i});
            lastElement++;
        }
        else
        {
            que.push_back({buffer,i});
            lastElement++;
        }
    }
    cout << que[0].first << "\n";
    for (int i = k+1; cin >> buffer; i++)
    {
        if (que.size() == 0)
        {
            que.push_front({buffer,i});
            lastElement = 0;
        }
        else
    {
        if (que[0].second == i-k)
        {
            que.pop_front();
            lastElement--;
        }
        if (que.size() == 0)
        {
            que.push_front({buffer,i});
            lastElement = 0;
        }
        else if (buffer > que[0].first)
        {
            que.clear();
            que.push_front({buffer,i});
            lastElement = 0;
        }
        else if (buffer > que[lastElement].first)
        {
            while(que[lastElement].first < buffer)
            {
                que.pop_back();
                lastElement--;
            }
            que.push_back({buffer,i});
            lastElement++;
        }
        else
        {
            que.push_back({buffer,i});
            lastElement++;
        }
     }
        cout << que[0].first << "\n";
    }
}
