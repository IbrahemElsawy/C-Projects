/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 1: contacts.h

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/



#pragma once // It accepts the compability with other compilers.

// The struct that is declared with the tag name being FullName.
struct FullName{

	// The char variables (firstName, middleInitial, and lastName) that are going to be declared with up to a certain number of characters.
	char firstName[31];
	char middleInitial[7];
	char lastName[35];

};

// The struct that is going to be declared with the tag name being FullAddress.
struct FullAddress
{
	// The variables (streetNumber, streetName, apartmentNumber, postalCode, and cityName) that are going to be declared as int and char with up to a certain number of characters (except for streetNumber and apartmentNumber).
	int streetNumber;
	char streetName[41];
	int apartmentNumber;
	char postalCode[8];
	char cityName[41];

};

// The struct that is going to be declared with the tag name being FullNumbers.
struct FullNumbers
{
	// The variables (cellNumber, homeNumber, and businessNumber) that are going to be declared as char with up to a certain number of chracters.
	char cellNumber[11];
	char homeNumber[11];
	char businessNumber[11];

};

// The struct that is going to be declared with the tag name being Contact.
struct Contact
{
	// The three structs that are going to be allocating their memory within the struct Contact with the identifiers being name, address, and numbers.
	struct FullName name;
	struct FullAddress address;
	struct FullNumbers numbers;


};

// The function prototype for getFullName.
void getFullName (struct FullName *);

// The function prototype for getFullAddress.
void getFullAddress (struct FullAddress *);

// The function prototype for getFullNumbers.
void getFullNumbers (struct FullNumbers *);

void clearKeyboard (void);

void pause (void);

int getInt (void);

int getIntInRange (int min, int max);

int yes (void);

int menu (void);

void contactManagerSystem (void);


