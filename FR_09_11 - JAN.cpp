#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string Input;
    unsigned long long int sum = 0;
    unsigned long long int J=0,A=0,N=0,buff=0;
    cin >> Input;
    for (int i = Input.length()-1; i > -1; i--)
    {
        if (Input[i] == 'N')
        {
            N++;
        }
        else if (Input[i] == 'A')
        {
            buff+=N;
        }
        else if (Input[i] == 'J')
        {
            sum += buff;
        }
    }
    cout << sum;
}
