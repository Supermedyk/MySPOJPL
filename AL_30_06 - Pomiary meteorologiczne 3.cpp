
#include <bits/stdc++.h>

// REALLY SLOW !!!

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tab[10001];

    deque<pair<int,int>> que;
    deque<pair<int,int>> sque;

    int k;
    int S;
    cin >> S;
    for (int i = 0; i < S; i++)
        cin >> tab[i];
    int T;
    cin >> T;
    while(T--)
    {
        que.clear();
        sque.clear();
        cin >> k;
        int lastElement = -1;
        int slastElement = -1;
        int val = INT_MIN;
        for (int i = 0; i < k; i++)
        {

            if (que.size() == 0)
            {
                que.push_front({tab[i],i});
                lastElement = 0;
            }
            else if (tab[i] > que[0].first)
            {
                que.clear();
                que.push_front({tab[i],i});
                lastElement = 0;
            }
            else if (tab[i] > que[lastElement].first)
            {
                while(que[lastElement].first < tab[i])
                {
                    que.pop_back();
                    lastElement--;
                }
                que.push_back({tab[i],i});
                lastElement++;
            }
            else
            {
                que.push_back({tab[i],i});
                lastElement++;
            }
            if (sque.size() == 0)
            {
                sque.push_front({tab[i],i});
                slastElement = 0;
            }
            else if (tab[i] < sque[0].first)
            {
                sque.clear();
                sque.push_front({tab[i],i});
                slastElement = 0;
            }
            else if (tab[i] < sque[slastElement].first)
            {
                while(sque[slastElement].first < tab[i])
                {
                    sque.pop_back();
                    slastElement--;
                }
                sque.push_back({tab[i],i});
                slastElement++;
            }
            else
            {
                sque.push_back({tab[i],i});
                slastElement++;
            }
        }
        val = que[0].first-sque[0].first;
        for (int i = k; i < S; i++)
        {

            if (que.size() == 0)
            {
                que.push_front({tab[i],i});
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
                    que.push_front({tab[i],i});
                    lastElement = 0;
                }
                else if (tab[i] > que[0].first)
                {
                    que.clear();
                    que.push_front({tab[i],i});
                    lastElement = 0;
                }
                else if (tab[i] > que[lastElement].first)
                {
                    while(que[lastElement].first < tab[i])
                    {
                        que.pop_back();
                        lastElement--;
                    }
                    que.push_back({tab[i],i});
                    lastElement++;
                }
                else
                {
                    que.push_back({tab[i],i});
                    lastElement++;
                }
            }
            if (sque.size() == 0)
            {
                sque.push_front({tab[i],i});
                slastElement = 0;
            }
            else
            {
                if (sque[0].second == i-k)
                {
                    sque.pop_front();
                    slastElement--;
                }
                if (sque.size() == 0)
                {
                    sque.push_front({tab[i],i});
                    slastElement = 0;
                }
                else if (tab[i] < sque[0].first)
                {
                    sque.clear();
                    sque.push_front({tab[i],i});
                    slastElement = 0;
                }
                else if (tab[i] < sque[slastElement].first)
                {
                    while(sque.back().first < tab[i])
                    {
                        sque.pop_back();
                        slastElement--;
                    }
                    sque.push_back({tab[i],i});
                    slastElement++;
                }
                else
                {
                    sque.push_back({tab[i],i});
                    slastElement++;
                }
            }
            if (que[0].first-sque[0].first > val)
                val = que[0].first-sque[0].first;
        }
        cout << val << "\n";
    }
}
