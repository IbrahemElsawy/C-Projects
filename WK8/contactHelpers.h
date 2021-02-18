/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 2: contactHelpers.h

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/

#pragma once // It accepts the compability with other compilers.

#include "contacts.h" // Includes the contacts header file, containing the structs and prototypes of the functions in this source file.

// The function prototypes for the functions in contactHelpers.c
void clearKeyboard(void);

void pause(void);

int getInt(void);

int getIntInRange(int min, int max);

int yes(void);

int menu(void);

void contactManagerSystem(void);

void getTenDigitPhone(char phoneNum[]);

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

void displayContactHeader(void);

void displayContactFooter(int count);

void displayContact(const struct Contact* contact);

void displayContacts(const struct Contact contacts[], int size);

void searchContacts(const struct Contact contacts[], int size);

void addContact(struct Contact contacts[], int size);

void updateContact(struct Contact contacts[], int size);

void deleteContact(struct Contact contacts[], int size);

void sortContacts(struct Contact contacts[], int size);

