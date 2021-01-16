#include "Account.h"

Account::Account()
{
	setName("");
	setId(000);
	setUsername("");
	setPassword("");
}

Account::Account(Account & object)
{
	this->name = object.getName();
	this->id = object.getId();
	this->username = object.getUsername();
	this->password = object.getPassword();
}

Account::~Account()
{

}


void Account::setName(string name)
{
	this->name = name;
}

void Account::setId(int id)
{
	this->id = id;
}

void Account::setUsername(string username)
{
	this->username = username;
}

void Account::setPassword(string password)
{
	this->password = password;
}

string Account::getName() const
{
	return this->name;
}

int Account::getId() const
{
	return this->id;
}

string Account::getUsername() const
{
	return this->username;
}

string Account::getPassword() const
{
	return this->password;
}

void Account::generateId()
{
	//generate a random id of 3 digits
	//example: 123
	unsigned seed = time(0);
	srand(seed);

	id = (rand() % (999 - 111)) + 111;
	cout << this->name << "'s id is: " << id << "." << endl;
}

void Account::askData()
{
	cout << "Enter the user's full name (first name and last name): ";
	cin.ignore();
	getline(cin, name);

	generateId();

	cout << "Enter the username of " << name << ": ";
	//cin.ignore();
	getline(cin, username);

	cout << "Enter the password of " << name << ": ";
	//cin.ignore();
	getline(cin, password);
}

void Account::encryptPassword()
{
	//cesar cipher

	char encrypt[100];
	encrypt[password.length() + 1] = '\0';

	unsigned seed = time(0);
	srand(seed);
	key = rand() % 12 + 1;

	//passing the password variable to the encrypt variable
	//string to char 
	strcpy_s(encrypt, password.c_str());

	for (int i = 0; encrypt[i] != '\0'; ++i)
	{
		if ((encrypt[i] >= 'a'&&encrypt[i] <= 'z') || (encrypt[i] >= 'A'&&encrypt[i] <= 'Z'))
		{
			encrypt[i] += key;
		}
		else if (encrypt[i] >= 'z' || encrypt[i] >= 'Z')
			encrypt[i] = encrypt[i] - 'z' + 'a' - 1;
	}

	//passing the encryption
	for (int i = 0; encrypt[i] != '\0'; i++)
		password[i] = encrypt[i];
}

void Account::decryptPassword()
{
	//cesar cipher

	char decrypt[100];
	decrypt[password.length() + 1] = '\0';

	//passing the password variable to the dencrypt variable
	//string to char 
	strcpy_s(decrypt, password.c_str());

	for (int i = 0; decrypt[i] != '\0'; ++i)
	{
		if ((decrypt[i] >= 'a'&& decrypt[i] <= 'z') || (decrypt[i] >= 'A'&& decrypt[i] <= 'Z')) //to lower all?
		{
			decrypt[i] -= key;
		}
		else if (decrypt[i] >= 'z' || decrypt[i] >= 'Z')
			decrypt[i] = decrypt[i] - 'z' - 'a' + 1;
	}

	//passing the encryption
	for (int i = 0; decrypt[i] != '\0'; i++)
		password[i] = decrypt[i];
}


void Account::inputFile()
{
	//the program will create a file for every name that you enter
	file.open(name.c_str(), ios::app);

	if (file.fail())
	{
		cout << "The file could not be created...";
		exit(1);
	}
	//writing data to the file
	file << this->id << endl;
	file << this->name << endl;
	file << this->username << endl;
	file << this->password << endl;
	//file<<'|';

	file.close();
}

void Account::askFile()
{
	//asking the name of the file that you want to open
	cout << "Enter the name of the person: ";
	cin.ignore();
	getline(cin, name);
	system("cls");
}

void Account::displayFile()
{
	// abriendo file para leer lo que tiene
	askFile();

	file.open(name.c_str(), ios::in);

	file >> id;
	cout << "ID: " << id << endl;
	file >> name;
	cout << "First name: " << name << endl;
	file >> name;
	cout << "Last name: " << name << endl;
	file >> username;
	cout << "Username: " << username << endl;
	file >> password;
	cout << "Password: " << password << endl;

	file.close();
}

void Account::login()
{

	//abriendo file para leer lo que tiene
	askFile();

	file.open(name.c_str(), ios::in);

	if (file.fail())
	{
		cout << "The file couldn't be open...";
		exit(1);
	}

	string temp;

	file >> id;
	file >> name;
	file >> temp; // So it eats the last name, and assigns the username and password correctly
	file >> username;
	cout << "Username: " << username << endl;
	file >> password;
	cout << "Password: " << password << endl;

	decryptPassword();

	cout << "\n\n\n------LOG-IN-INTERFACE------\n\n\n";
	const int SIZE = 100;
	char Password[SIZE], Username[SIZE];
	Password[password.length() + 1] = '\0';
	Username[username.length() + 1] = '\0';

	char input_username[SIZE];
	char input_password[SIZE];

	cout << "Enter the username: ";
	cin.getline(input_username, SIZE);

	cout << "Enter the password: ";
	cin.getline(input_password, SIZE);

	strcpy_s(Username, username.c_str());
	strcpy_s(Password, password.c_str());

	file.close();
	while (!((strcmp(input_username, Username) == 0) || (strcmp(input_password, Password) == 0)))
	{
		system("cls");
		cout << "The username or the password is incorrect, please try again...\n\n";

		cout << "Enter the username: ";
		cin.getline(input_username, SIZE);

		cout << "Enter the password: ";
		cin.getline(input_password, SIZE);

		if ((strcmp(input_username, Username) == 0) || (strcmp(input_password, Password) == 0))
			cout << "\nLogged in!\n";
	}
}