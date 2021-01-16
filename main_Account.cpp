#include <conio.h>
#include "Account.h"

using namespace std;

void intro()
{
	cout << "\nThis is a generic authentication engine.\n"
		<< "You can create new accounts and print their credentials.\n"
		<< "\nPress any key to continue...";
	_getch();
}

void menu()
{
	cout << "1. Add a new account\n"
		<< "2. Login\n"
		<< "3. Show account record\n"
		<< "4. Exit the program\n"
		<< "Select one of the options: ";
}

void addAccount(Account o)
{
	system("cls");
	o.askData();
	o.encryptPassword();
	o.inputFile();
	cout << "Account created successfully.\n\n";
}

void login(Account o)
{
	system("cls");
	o.login();
	cout << "\n\n";
}

void displayFile(Account o)
{
	system("cls");
	o.displayFile();
	cout << "\n\n";
}

int main()
{
	Account user;
	char again;
	int choice;

	intro();

	do
	{
		system("cls");
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1: 
			addAccount(user);
			break;

		case 2: 
			login(user);
			break;

		case 3: 
			displayFile(user);
			break;

		case 4: 
			cout << "\nHave a nice day!\n";
			break;

		default:
			cout << "\nError; enter a valid choice [1-3].\n";
		}
		if (choice != 4)
		{
			cout << "Do you want to run the program again (Y / N)?: ";
			cin >> again;
			if (again == 'n')
				cout << "\nHave a nice day!\n";
		}
		else
		{
			again = 'n';
		}
	} while (again == 'y' || again == 'Y');
	system("pause");
	return 0;
}