#include <bits/stdc++.h>

using namespace std;

class word
{
public:
    int amount = 1;
    string input = "";
    string output ="";
    void compress()
    {
        output = "";
        int howManyTimes = 1;
        char lastChar = input[0];
        for (int i = 1; i < input.length(); i++)
        {
            if (lastChar == input[i])
            {
                howManyTimes++;
            }
            else
            {
                if (howManyTimes <= 3)
                {
                    for (int k = 0; k < howManyTimes; k++)
                    {
                        output += lastChar;
                    }
                }
                else
                {
                    output += lastChar;
                    output += '*';
                    string numBuff = "";
                    while(howManyTimes != 0)
                    {
                        numBuff += (howManyTimes % 10) +'0';
                        howManyTimes /= 10;
                    }
                    reverse(numBuff.begin(),numBuff.end());
                    output += numBuff;
                }
                lastChar = input[i];
                howManyTimes = 1;
            }
        }
        if (howManyTimes <= 3)
        {
            for (int k = 0; k < howManyTimes; k++)
            {
                output += lastChar;
            }
        }
        else
        {
            output += lastChar;
            output += '*';
            string numBuff = "";
            while(howManyTimes != 0)
            {
                numBuff += (howManyTimes % 10) + '0';
                howManyTimes /= 10;
            }
            reverse(numBuff.begin(),numBuff.end());
            output += numBuff;
        }
    }
    void decompress()
    {
        output = "";
        int howManyTimes = 1;
        int buffAmount = 1;
        char lastChar = input[0];
        bool spec = false;
        for (int i = 1; i < input.length(); i++)
        {

            if (spec == true)
            {
                buffAmount = input[i]-'0';
                i++;
                for (; i < input.length(); i++)
                {
                    buffAmount*=10;
                    buffAmount+=input[i]-'0';
                }
                amount = buffAmount;
                howManyTimes = 0;
            }
            else if (lastChar != input[i])
            {
                if (input[i] == '*')
                {
                    bool catched = false;
                    i++;
                    howManyTimes = input[i]-'0';
                    i++;
                    if (input[i] == '/')
                    {
                        spec = true;
                        for (int k = 0; k < howManyTimes; k++)
                        {
                            output += lastChar;
                        }
                    }
                    else
                    {
                        for (; i<input.length(); i++)
                        {
                            if (input[i] < '0' || input[i] > '9')
                            {
                                for (int k = 0; k < howManyTimes; k++)
                                {
                                    output += lastChar;
                                }
                                if (input[i] != '/')
                                {
                                    lastChar = input[i];
                                    howManyTimes = 1;
                                    catched = true;
                                }
                                else
                                {
                                    spec=true;
                                }
                                break;
                            }
                            howManyTimes*=10;
                            howManyTimes+=input[i]-'0';

                        }
                        if(catched != true)
                        {
                            for (int k = 0; k < howManyTimes; k++)
                            {
                                output += lastChar;
                            }
                            howManyTimes = 0;
                        }
                    }
                }
                else if (input[i] == '/')
                {
                    for (int k = 0; k < howManyTimes; k++)
                    {
                        output += lastChar;
                    }
                    i++;
                    buffAmount = input[i]-'0';
                    i++;
                    for (; i<input.length(); i++)
                    {
                        buffAmount*= 10;
                        buffAmount+=input[i]-'0';

                    }
                    amount = buffAmount;
                    howManyTimes = 0;
                }
                else
                {
                    for (int k = 0; k < howManyTimes; k++)
                    {
                        output += lastChar;
                    }
                    lastChar = input[i];
                    howManyTimes = 1;
                }
            }
            else
            {
                howManyTimes++;
            }
        }
        if (howManyTimes != 0)
        {
            for (int k = 0; k < howManyTimes; k++)
            {
                output += lastChar;
            }
        }
    }
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    word bufferClass;
    int index = -1;
    vector<word> vecOfWords;
    string bufferWord;
    string command;
    cin >> command;
    if (command == "KOMPRESJA")
    {
        while(cin >> bufferWord)
        {
            if (bufferWord == bufferClass.input)
            {
                vecOfWords[index].amount++;
            }
            else
            {
                index++;
                bufferClass.input = bufferWord;
                bufferClass.compress();
                vecOfWords.push_back(bufferClass);
            }
        }
        for (auto i: vecOfWords)
        {
            if (i.output.length() == 1 && i.amount == 2)
            {
                cout << i.output <<" "<<i.output << " ";
            }
            else if (i.amount != 1)
            {

                cout << i.output << "/" << i.amount << " ";

            }
            else
            {
                cout << i.output << " ";
            }
        }
    }
    else
    {
        while(cin >> bufferWord)
        {
            bufferClass.amount = 1;
            bufferClass.input = bufferWord;
            bufferClass.decompress();
            vecOfWords.push_back(bufferClass);
        }
        for (auto i: vecOfWords)
        {
            for (int k = 0; k < i.amount; k++)
            {
                cout << i.output << " ";
            }
        }
    }
}
