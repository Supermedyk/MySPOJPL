#include <bits/stdc++.h>

using namespace std;

int tabA[100001];
int tabB[100001];

int bin_Search(int arr[], int target, int end)
{

    if (target > arr[0]) return -1;
    if (target <= arr[end-1]) return end;


    int start = 0;

    int ans = end;
    while (start <= end)
    {

       int mid = (start+end)/2;
       if (arr[mid] >= target)
       {
           start = mid+1;
       }
       else if (arr[mid] < target)
       {
           ans = mid;
           end = mid-1;
       }

    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);


    int amountOfJokes;
    cin >> amountOfJokes;
    int lastA = INT_MAX;
    int lastB = INT_MAX;
    int a;
    int b;
    for (int i = 0; i < amountOfJokes; i++)
    {
        cin >> a >> b;
        if (a < lastA)
        {
            lastA = a;

        }
        tabA[i] = lastA;
        if (b < lastB)
        {
            lastB = b;
        }
        tabB[i] = lastB;
    }

    int days;
    cin >> days;
    for (int i = 0; i < days; i++)
    {
        cin >> a >> b;
        int indexA = bin_Search(tabA,a,amountOfJokes);
        int indexB = bin_Search(tabB,b,amountOfJokes);
        if (indexA == indexB)
        {
            cout << "Remis\n";
        }
        else if (indexA > indexB)
        {
            cout << "Karol\n";
        }
        else
        {
            cout << "Tadeusz\n";
        }
    }
}
