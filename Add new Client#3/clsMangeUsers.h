#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include "clsMainScreen.h"
#include"clsBankClient.h"
#include"clsString.h"
#include"clsUserListScreen.h"
#include<iomanip>
#include"clsAddNewUserScreen.h"
#include"clsDeletedUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;
class clsMangeUsers : protected clsScreen
{
private:
	enum EnManageUserse {
		enList = 1
		, enAddnew = 2
		,enDeleted = 3
		,enUpdate = 4
		,enFind = 5
		,enBackMain = 6
	};
	static int ReadManagerUsers() {
		cout << setw(37) << left << "" << "Choose what do you want ? [1-6]";
		int choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return choice;
	}
	static void _GobackMainMenu() {
		cout << "\nwell\n";
		system("pause>0");
		ShowManageScreen();
	}
	static void ShowList() {
		clsUserListScreen::ShowUserList();
	}
	static void AddNew() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void Deleted() {
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void UpdateNew() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void FindNew() {
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _PerforamManageUseres(EnManageUserse ManageUsers) {
		switch (ManageUsers)
		{
		case clsMangeUsers::enList:
			system("cls");
			ShowList();
			_GobackMainMenu();
			break;
		case clsMangeUsers::enAddnew:
			system("cls");
			AddNew();
			_GobackMainMenu();
			break;
		case clsMangeUsers::enDeleted:
			system("cls");
			Deleted();
			_GobackMainMenu();
			break;
		case clsMangeUsers::enUpdate:
			system("cls");
			UpdateNew();
			_GobackMainMenu();
			break;
		case clsMangeUsers::enFind:
			system("cls");
			FindNew();
			_GobackMainMenu();
			break;
		case clsMangeUsers::enBackMain:
			break;
		default:
			break;
		}
	}
public:
	static void ShowManageScreen() {
		system("cls");
		   
		_DrawScreen("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerforamManageUseres((EnManageUserse)ReadManagerUsers());


	}
};

