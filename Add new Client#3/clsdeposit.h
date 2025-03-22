#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
class clsdeposit : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
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
    static string _ReadAccountNumber() {
        string AccountNumber = "";
        cout << "\n Please enter your account Number \n";
        cin >> AccountNumber;
        return AccountNumber;
    }
public:
    static void ShowDepoist() {
        _DrawScreen("\t Depoist Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n Client with [" << AccountNumber << "] doesn't exists\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        double Amount = 0;
        cout << "\n Please enter your dopist ?\n";
        Amount = clsInputValidate::ReadDblNumber();
        cout << "\n Are you sure want to dopist this account ? y/n";
        char ans = 'n';
        cin >> ans;
            if (ans == 'Y' || ans == 'y')
            {
                Client1.Depoist(Amount);
                cout << "\nAmount Deposited Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else {
                cout << "\nOperation was cancelled.\n";
            }
    }

};

