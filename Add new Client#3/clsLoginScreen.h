#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global22.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << (3 - FaildLoginCount)
                    << " Trial(s) to login.\n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\nYour are Locked after 3 faild trails \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            Current = clsUser::Find(Username, Password);

            LoginFaild = Current.IsEmpty();

        } while (LoginFaild);
        Current.Registerlogin();
        clsMainScreen::ShowMainMenu();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreen("\t    Login Screen");
        return _Login();

    }

};

