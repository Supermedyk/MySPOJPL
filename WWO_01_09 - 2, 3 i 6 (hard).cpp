#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    int whichNow = 0;
    bool pass = false;
    bool another = false;
    cin >> t;
    while(t--)
    {
        whichNow = 0;
        pass = true;
        another = true;
        string in;
        cin >> in;
        if (in.length() == 1)
        {
            pass = true;
        }
        else
        {
            if (in[0] == 'a')
            {
                whichNow = 2;
                for (int i = 1; i < in.length(); i++)
                {
                    if (whichNow == 1)
                    {
                        if (in[i] != 'a')
                        {
                            another = false;
                            break;
                        }
                        whichNow++;
                    }
                    else if (whichNow == 2)
                    {
                        if (in[i] != 'b')
                        {
                            another = false;
                            break;
                        }
                        whichNow++;
                    }
                    else if (whichNow == 3)
                    {
                        if (in[i] != 'a')
                        {
                            another = false;
                            break;
                        }
                        whichNow++;
                    }
                    else if (whichNow == 4)
                    {
                        if (i+1 == in.length())
                        {
                            another = false;
                            break;
                        }
                        else if (in[i] == 'a' && in[i+1] == 'b')
                        {
                            whichNow = 1;
                            i++;
                        }
                        else
                        {
                            another = false;
                            break;
                        }
                    }
                }
                if (another == false)
                {
                    whichNow = 4;
                    for (int i = 1; i < in.length(); i++)
                    {
                        if (whichNow == 1)
                        {
                            if (in[i] != 'a')
                            {
                                pass = false;
                                break;
                            }
                            whichNow++;
                        }
                        else if (whichNow == 2)
                        {
                            if (in[i] != 'b')
                            {
                                pass = false;
                                break;
                            }
                            whichNow++;
                        }
                        else if (whichNow == 3)
                        {
                            if (in[i] != 'a')
                            {
                                pass = false;
                                break;
                            }
                            whichNow++;
                        }
                        else if (whichNow == 4)
                        {
                            if (i+1 == in.length())
                            {
                                pass = false;
                                break;
                            }
                            else if (in[i] == 'a' && in[i+1] == 'b')
                            {
                                whichNow = 1;
                                i++;
                            }
                            else
                            {
                                pass = false;
                                break;
                            }
                        }
                    }
                    if (pass == false)
                    {
                        whichNow = 4;
                        for (int i = 0; i < in.length(); i++)
                        {
                            if (whichNow == 1)
                            {
                                if (in[i] != 'a')
                                {
                                    pass = true;
                                    break;
                                }
                                whichNow++;
                            }
                            else if (whichNow == 2)
                            {
                                if (in[i] != 'b')
                                {
                                    pass = true;
                                    break;
                                }
                                whichNow++;
                            }
                            else if (whichNow == 3)
                            {
                                if (in[i] != 'a')
                                {
                                    pass = true;
                                    break;
                                }
                                whichNow++;
                            }
                            else if (whichNow == 4)
                            {
                                if (i+1 == in.length())
                                {
                                    pass = true;
                                    break;
                                }
                                else if (in[i] == 'a' && in[i+1] == 'b')
                                {
                                    whichNow = 1;
                                    i++;
                                }
                                else
                                {
                                    pass = true;
                                    break;
                                }
                            }
                        }
                        if (pass == true)
                            pass = false;
                        else
                            pass = true;
                    }

                }
                else
                    pass = true;
            }

            else
            {
                whichNow = 3;
                for (int i = 1; i < in.length(); i++)
                {
                    if (whichNow == 1)
                    {
                        if (in[i] != 'a')
                        {
                            another = false;
                            break;
                        }
                        whichNow++;
                    }
                    else if (whichNow == 2)
                    {
                        if (in[i] != 'b')
                        {
                            another = false;
                            break;
                        }
                        whichNow++;
                    }
                    else if (whichNow == 3)
                    {
                        if (in[i] != 'a')
                        {
                            another = false;
                            break;
                        }
                        whichNow++;
                    }
                    else if (whichNow == 4)
                    {
                        if (i+1 == in.length())
                        {
                            another = false;
                            break;
                        }
                        else if (in[i] == 'a' && in[i+1] == 'b')
                        {
                            whichNow = 1;
                            i++;
                        }
                        else
                        {
                            another = false;
                            break;
                        }
                    }
                }
                if (another == false)
                    pass = false;
            }
        }
        if (pass == false)
            cout << "nie\n";
        else
            cout << "tak\n";

    }
}

