/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 2: contacts.h

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/



#pragma once // It accepts the compability with other compilers.

#ifndef CONTACT_H_
#define CONTACT_H_
// The struct that is declared with the tag name being FullName.
struct FullName
{

	// The char variables (firstName, middleInitial, and lastName) that are going to be declared with up to a certain number of characters.
	char firstName[31];
	char middleInitial[7];
	char lastName[35];

};

// The struct that is going to be declared with the tag name being FullAddress.
struct FullAddress
{
	// The variables (streetNumber, street, apartmentNumber, postalCode, and city) that are going to be declared as int and char with up to a certain number of characters (except for streetNumber and apartmentNumber).
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];

};

// The struct that is going to be declared with the tag name being FullNumbers.
struct FullNumbers
{
	// The variables (cell, home, and business) that are going to be declared as char with up to a certain number of chracters.
	char cell[12];
	char home[12];
	char business[12];

};

// The struct that is going to be declared with the tag name being Contact.
struct Contact
{
	// The three structs that are going to be allocating their memory within the struct Contact with the identifiers being name, address, and numbers.
	struct FullName name;
	struct FullAddress address;
	struct FullNumbers numbers;


};

// The function prototype for getName.
void getName(struct FullName* name);

// The function prototype for getAddress.
void getAddress(struct FullAddress* address);

// The function prototype for getNumbers.
void getNumbers(struct FullNumbers* numbers);

// The function prototype for getContact.
void getContact(struct Contact* contact);

#endif


