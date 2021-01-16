/*
Programmers:
Sebastian Matthews
Kevin Figueroa Figueroa
Jonathan Camacho Ortega

Your project consists of the creation of a generic authentication engine.  
A console implementation for users to create new accounts in which each user will indicate: 
Name, Last Name, username, and password.
The program must create and assign a user account number.  
It must also encode the user's password using a robust encryption algorithm, i.e. hash.  
Users' data will be stored in a file.  
The program must also allow for a user's record to be printed via his her account number.  
The program must include at least one class.
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class Account
{

private:
	fstream file;
	string name;
	string username;
	string password;
	int id, key;

public:

	Account();										//default constructor
	Account(Account & object);					//cpy constructor
	~Account();									//destructor

	void setName(string);							//change the value of name
	void setId(int);								//change the value of id
	void setUsername(string);						//change the value of username
	void setPassword(string);						//change the value of password

	string getName() const;							//return this->name (private)
	int getId() const;								//return this->id (private)
	string getUsername() const;						//return this->username (private)
	string getPassword() const;						//return this->password (private)

	void generateId();								//generate the id of the person
	void askData();									//ask the user 

	void encryptPassword();							//encrypt password
	void decryptPassword();							//decrypt the password
	void inputFile();								//save the data of the person(name,username,password,id)

	void askFile();									//ask the user the name of the file 
	void displayFile();								//print the file of the user input

	void login();
};