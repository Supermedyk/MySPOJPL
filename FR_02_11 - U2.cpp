#include <bits/stdc++.h>

using namespace std;

bool isItNegative;

unsigned long long tab[60]=
{
1,
2,
4,
8,
16,
32,
64,
128,
256,
512,
1024,
2048,
4096,
8192,
16384,
32768,
65536,
131072,
262144,
524288,
1048576,
2097152,
4194304,
8388608,
16777216,
33554432,
67108864,
134217728,
268435456,
536870912,
1073741824,
2147483648,
4294967296,
8589934592,
17179869184,
34359738368,
68719476736,
137438953472,
274877906944,
549755813888,
1099511627776,
2199023255552,
4398046511104,
8796093022208,
17592186044416,
35184372088832,
70368744177664,
140737488355328,
281474976710656,
562949953421312,
1125899906842624,
2251799813685248,
4503599627370496,
9007199254740992,
18014398509481984,
36028797018963968,
72057594037927936,
144115188075855872,
288230376151711744,
576460752303423488
};


void fastIO(unsigned long long &in)
{
    in = 0;
    char c = getchar();
    if (c == '-')
    {
        isItNegative = true;
        c = getchar();
    }
    for(;c >= '0' && c<='9'; c=  getchar())
    {
        in = in*10+(c-'0');
    }
}

string decToBin(unsigned long long number, unsigned long long amountOfBits, bool &pass)
{
    int ctr = 0;
    string res = "";
    while(ctr != amountOfBits)
    {
        res += ((number%2)+'0');
        number/=2;
        ctr++;
    }

    if (number != 0)
        pass = false;
    res += '0';
    reverse(res.begin(),res.end());
    return res;
}
string addOne(string number, bool &pass)
{
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] == '0')
        {
            number[i] = '1';
        }
        else
        {
            number[i] = '0';
        }
    }
    int index = number.length()-1;
    while(index != -1 && number[index] == '1')
    {
        number[index] = '0';
        index--;
    }
    number[index] = '1';
    return number;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	unsigned long long t;
	unsigned long long number,amountOfBits;
	bool pass;
	string output = "";
	fastIO(t);
	while(t--)
	{
		pass = true;
		isItNegative = false;
		output = "";
		fastIO(number);
		fastIO(amountOfBits);
        if (isItNegative)
        {
            if (amountOfBits <= 60 && tab[amountOfBits-1] < number)
            {
                cout << "niewykonalne\n";
            }
            else if (amountOfBits <= 60 && tab[amountOfBits-1] == number)
            {
                cout << "1" << string(amountOfBits-1,'0') << "\n";
            }
            else
            {
                output = decToBin(number,amountOfBits,pass);
                output.erase(output.begin());
                output = addOne(output,pass);
                cout << output << "\n";
            }
        }
        else
        {
            output = decToBin(number,amountOfBits-1,pass);
            if (pass)
            {
                cout << output << "\n";
            }
            else
            {
                cout << "niewykonalne\n";
            }
        }
	}
}
