#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include"clsClientLists.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsMangeUsers.h"
#include"Global22.h"
#include <iomanip>
class clsMainScreen : protected clsScreen
{
private:
	enum eMainmenu {
		eListClients = 1, 
		eAddNewClient = 2,
		eUpdateCleint = 3,
		eDeleteClient = 4,
		eFindClient = 5,
		eShowTransactions = 6,
		eManagerUsers = 7,
        eLoginRegister =8,
		eLogout = 9
	};
	static short _ReadMainmenu() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
		return Choice;
	}
	static void _BackToMenu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenu();

		
	}
    static void _ShowAllClientsScreen()
    {
        clsClientLists::ShowListsClients();


    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        
        clsDeleteClientScreen::ShowDeletedAccount();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsScreen();

    }

    static void _ShowManageUsersMenue()
    {
        clsMangeUsers::ShowManageScreen();

    }
    static void _LoginRegisterScreen() {

    }
    static void _Logout()
    {
        Current = clsUser::Find("", "");

    }
    static void _PerformMainMenuOp(eMainmenu MainOption) {
        switch (MainOption)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _BackToMenu();
            break;
            
        case clsMainScreen::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _BackToMenu();
            break;
       
            
        case clsMainScreen::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _BackToMenu();
            break;
           

        case clsMainScreen::eUpdateCleint:
            system("cls");
            _ShowUpdateClientScreen();
            _BackToMenu();
            break;


        case clsMainScreen::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _BackToMenu();
            break;
            
        case clsMainScreen::eShowTransactions:
            system("cls");
            _ShowTransactionsMenue();
            _BackToMenu();
            break;
            
        case clsMainScreen::eManagerUsers:
            system("cls");
            _ShowManageUsersMenue();
            _BackToMenu();
            break;

        case clsMainScreen::eLoginRegister:
            system("cls");
            _LoginRegisterScreen();
            _BackToMenu();
            break;

        case clsMainScreen::eLogout:
            
            system("cls");
            _Logout();
            break;
        
        }
    }
    public:
        static void ShowMainMenu() {
            system("cls");
            cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate::GetSystemDate()) << endl;
            _DrawScreen("\t\t Main Screen");
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[4] Deleted Account.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Registers.\n";
            cout << setw(37) << left << "" << "\t[9] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerformMainMenuOp((eMainmenu)_ReadMainmenu());
        }


};

