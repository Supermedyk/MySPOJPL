#include <bits/stdc++.h>

using namespace std;

int tab[366];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int holidays;
    string day;
    string month;
    deque<int> val;
    int t;
    int le;
    int wold;
    int buff;
    cin >> holidays;
    cin >> day;
    if (day == "sobota")
    {
        buff = 0;
    }
    else if (day == "poniedzialek")
    {
        buff = 5;
    }
    else if (day == "wtorek")
        buff = 4;
    else if (day == "sroda")
        buff = 3;
    else if (day == "czwartek")
        buff = 2;
    else if (day == "piatek")
        buff = 1;
    else if (day == "niedziela")
    {
        tab[1] = 1;
        buff = 6;
    }
    for (int i = buff+1; i < 366; i+= 7)
    {
        tab[i] = 1;
        if (i+1 != 366)
        {
            tab[i+1] = 1;
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> month;
        if (month == "styczen")
            wold = 0;
        else if (month == "luty")
            wold = 31;
        else if  (month == "marzec")
            wold = 59;
        else if (month == "kwiecien")
            wold = 90;
        else if (month == "maj")
            wold = 120;
        else if (month == "czerwiec")
            wold = 151;
        else if (month == "lipiec")
            wold = 181;
        else if (month == "sierpien")
            wold = 212;
        else if (month == "wrzesien")
            wold = 243;
        else if (month == "pazdziernik")
            wold = 273;
        else if (month == "listopad")
            wold = 304;
        else if (month == "grudzien")
            wold = 334;
        cin >> buff;
        for (int j = 0; j < buff; j++)
        {
            cin >> le;
            tab[le+wold] = 1;
        }
    }
    int longest = 0;
    int buffHolidays = holidays;
    val.clear();
    for (int i = 1; i < 366; i++)
    {
        if (tab[i] == 0)
        {
            if (buffHolidays != 0)
            {
                val.push_back(0);
                buffHolidays--;
            }
            else
            {
                if (val.size() > longest)
                    longest = val.size();
                if (val.front() == 0)
                {
                    val.pop_front();
                    val.push_back(0);
                }
                else
                {
                    while(val.front() != 0)
                    {
                        val.pop_front();
                    }
                    val.pop_front();
                    val.push_back(0);
                }
            }
        }
        else
        {
            val.push_back(1);
        }
    }
    if (val.size() > longest)
        longest = val.size();
    cout << longest;
}
