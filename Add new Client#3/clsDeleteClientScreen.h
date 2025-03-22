#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsDeleteClientScreen : protected clsScreen
{
private:
    static void PrintClient(clsBankClient Client) {
        
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << Client.FirstName;
            cout << "\nLastName    : " << Client.LastName;
            cout << "\nFull Name   : " << Client.FullName();
            cout << "\nEmail       : " << Client.Email;
            cout << "\nPhone       : " << Client.Phone;
            cout << "\nAcc. Number : " << Client.AccountNumber();
            cout << "\nPassword    : " << Client.PinCode;
            cout << "\nBalance     : " << Client.AccountBalance;
            cout << "\n___________________\n";

        
    }
public:
    static void ShowDeletedAccount()
    {
        _DrawScreen("\t Deleted account screen");
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::Find(AccountNumber);
        PrintClient(NewClient);
        cout << "Are you want to delete this client y/n ? : ";
        char answer = 'n';
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            if (NewClient.Delete())
            {
                cout << "\n Client deleted successfully :-) \n";
                PrintClient(NewClient);
            }
            else {
                cout << "\n Error Client was not Deleted\n";
            }
        }


    }
};

