#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iostream>
#include<string>
#include<iomanip>
#include"clsdeposit.h"
#include"clsWithdraw.h"
class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenuOp {
	eDeposit = 1, eWithdrw = 2, eShowTotalBalance = 3, eShowMainMenu = 4
	};
	static int ReadTransactions() {
		cout << setw(37) << left << " " << "Chosee what you want [1] to [4]";
		int choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter Number between 1 to 4 ? ");
		return choice;
	}
	static void _ShowDepoistScreen() {
		clsdeposit::ShowDepoist();
	}
	static void _ShowWithdrwScreen() {
		clsWithdraw::ShowWithdraw();
	}
	static void _ShowTotalBalanceScreen() {
		cout << "\n We will show here later\n";
	}
	static void _ShowMainMenuScreen() {
		cout << "\n We will show here later\n";
	}
	static void _PerfomEnumOp(enTransactionsMenuOp MainmenuOption) {
		switch (MainmenuOption)
		{
		case clsTransactionsScreen::eDeposit:
			system("cls");
			_ShowDepoistScreen();
			_ShowMainMenuScreen();
			
			break;
		case clsTransactionsScreen::eWithdrw:
			system("cls");
			_ShowWithdrwScreen();
			_ShowMainMenuScreen();
			break;
		case clsTransactionsScreen::eShowTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_ShowMainMenuScreen();
			break;
		case clsTransactionsScreen::eShowMainMenu:
			break;
		default:
			break;
		}
	}
public:
	static void ShowTransactionsScreen() {
		_DrawScreen("\t Transactions screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerfomEnumOp((enTransactionsMenuOp)ReadTransactions());
	}
};

