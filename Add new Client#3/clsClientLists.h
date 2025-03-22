#pragma once
#include<iostream>
#include"clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
class clsClientLists : protected clsScreen
{
private:
    static void PrintClientrecord(clsBankClient Client) {

        cout << "|" << setw(15) << left << Client.AccountNumber();
        cout << "|" << setw(20) << left << Client.FullName();
        cout << "|" << setw(20) << left << Client.Phone;
        cout << "|" << setw(20) << left << Client.Email;
        cout << "|" << setw(12) << left << Client.AccountBalance;
    }
public:

    static void ShowListsClients() {

        vector<clsBankClient> vClients = clsBankClient::getClientLists();
        string Title = "\t Clients name screen";
        string subTitle = "\t (" + to_string(vClients.size()) + ") Clients";
        _DrawScreen(Title, subTitle);
        cout << "\n\t\t\t\t Clint list (" << vClients.size() << ") Clients";
        cout << "\n--------------------------------------------------------";
        cout << "---------------------------------------------------------\n";
        cout << "|" << setw(15) << left << "Account Nmber";
        cout << "|" << setw(20) << left << "FullName";
        cout << "|" << setw(20) << left << "Phone";
        cout << "|" << setw(20) << left << "Email";
        cout << "|" << setw(12) << left << "Account Balance";
        if (vClients.size() == 0)
        {
            cout << "\t\t\t there is not accounts here !";
        }
        else
        {
            for (clsBankClient Client : vClients)
            {
                PrintClientrecord(Client);
                cout << endl;
            }
        }
        cout << "\nThe total balances is : \n" << clsBankClient::GetTotalBalances();
    }

    
};