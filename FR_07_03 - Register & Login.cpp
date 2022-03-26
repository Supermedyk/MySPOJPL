#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    string LoginInput = "";
    string buffer = "";
    string PasswordInput = "";
    vector <string> Logins;
    vector <string> Passwords;
    vector <string>::iterator it;
    string command = "";
    string Number = "";
    int Loops;
    int index;
    bool DidPassed = false;
    bool Big;
    bool Small;
    bool Special;
    bool NumberG;
    while(getline(cin,buffer))
    {
        Number = "";
        command = "";
        for (int i = 0; i < buffer.length(); i++)
        {
            if (buffer[i] != ' ')
                command += buffer[i];
            else
            {
                index = i;
                break;
            }

        }
        for (int i = index+1; i < buffer.length(); i++)
        {
            Number+=buffer[i];
        }
        Loops = stoi(Number);
        if (command == "register")
        {
            while(Loops--)
            {
                NumberG = false;
                Special = false;
                Big = false;
                Small = false;
                DidPassed = false;
                LoginInput = "";
                PasswordInput = "";
                getline(cin,buffer);
                for (int i = 0; i < buffer.length(); i++)
                {
                    if (buffer[i] != ' ')
                        LoginInput+= buffer[i];
                    else
                    {
                        index = i;
                        break;
                    }
                }
                for (int i = index+1; i < buffer.length(); i++)
                {
                    if (buffer[i] != ' ')
                        PasswordInput += buffer[i];
                    else
                    {
                        break;
                    }
                }
                for (int i = 0; i < LoginInput.length(); i++)
                {
                    if (LoginInput[i] >= 97 && LoginInput[i] <= 122)
                        LoginInput[i] -= 32;
                }
                if (LoginInput.length() >= 3 && LoginInput.length() <= 12 && PasswordInput.length() >= 5 && PasswordInput.length() <= 15)
                {
                    for(int i = 0; i < LoginInput.length(); i++)
                    {
                        if ((LoginInput[i] <= 90 && LoginInput[i] >= 65) || (LoginInput[i] <= 57 && LoginInput[i] >= 48))
                        {
                            ;
                        }
                        else
                        {
                            DidPassed = true;
                            break;
                        }
                    }
                    if (DidPassed == false)
                    {
                        for (int i = 0; i < PasswordInput.length(); i++)
                        {
                            if (PasswordInput[i] >= 48 && PasswordInput[i] <= 57)
                            {
                                NumberG = true;
                            }
                            else if (PasswordInput[i] >= 97 && PasswordInput[i] <= 122)
                            {
                                Small = true;
                            }
                            else if (PasswordInput[i] >= 65 && PasswordInput[i] <= 90)
                            {
                                Big = true;
                            }
                            else
                            {
                                Special = true;
                            }

                        }
                        if (NumberG == true && Special == true && Big == true && Small == true)
                        {
                            if(find(Logins.begin(), Logins.end(), LoginInput) ==  Logins.end())
                            {
                                Logins.push_back(LoginInput);
                                Passwords.push_back(PasswordInput);
                                cout << "Zarejestrowano\n";
                            }
                            else
                            {
                                cout << "Login zajety\n";
                            }
                        }
                        else
                        {
                            cout << "Blad\n";
                        }
                    }
                    else
                    {
                        cout << "Blad\n";
                    }
                }
                else
                {
                    cout << "Blad\n";
                }

            }


        }
        else if (command == "login")
        {


            while(Loops--)
            {
                LoginInput = "";
                PasswordInput = "";
                getline(cin,buffer);
                for (int i = 0; i < buffer.length(); i++)
                {
                    if (buffer[i] != ' ')
                        LoginInput+= buffer[i];
                    else
                    {
                        index = i;
                        break;
                    }
                }
                for (int i = index+1; i < buffer.length(); i++)
                {
                    if (buffer[i] !=' ')
                        PasswordInput += buffer[i];
                    else
                    {
                        break;
                    }
                }
                for (int i = 0; i < LoginInput.length(); i++)
                {
                    if (LoginInput[i] >= 97 && LoginInput[i] <= 122)
                        LoginInput[i] -= 32;
                }
                it = find(Logins.begin(),Logins.end(),LoginInput);
                if( it == Logins.end())
                {
                    cout << "Konto nie istnieje\n";
                }
                else
                {
                    if (Passwords[it-Logins.begin()] == PasswordInput)
                        cout << "Zalogowano\n";
                    else
                    {
                        cout << "Zle haslo\n";
                    }

                }

            }


        }

    }
}
