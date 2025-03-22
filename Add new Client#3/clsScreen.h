#pragma once
#include <iostream>
#include"Global22.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreen(string Title, string subTitle = "") {
		cout << "\t\t\t\t\t___________________";
		cout << "\n\n\t\t\t\t\t " << Title;
		if (subTitle != "")
		{
			cout << "\n\t\t\t\t\t " << subTitle;
		}
		cout << "\t\t\t\t\t___________________";
		cout << "\n\t\t\t\t User :" << Current.UserName << "\n";
		cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate::GetSystemDate()) << endl;

	}
};

