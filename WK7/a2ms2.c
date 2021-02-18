/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 2: a2ms2.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // Defines no warnings for scanf lines when building the solution for the program.

#include <stdio.h> // Includes the inputs/output facilities of this program.
#include "contacts.h" // Includes the contacts header file, containing the structs and function prototypes.
#include "contactHelpers.h" // Includes the contactHelpers header file, containing the function prototypes from contactHelpers.c source file.

// The function prototype for printSectionHeader function.
void printSectionHeader (const char*);

// The main function that has a return type of int and no parameters.
int main (void)
{
    // Intiailizes a range of values ( { { { 0  } } } ) for struct Contact named contact.
    struct Contact contact = { { { '\0' } } };
    int tstInteger; // Declares tstInteger as an int variable.

    // Displays the section header and the output messages between the quotes and the yes function.
    //--------------------------------------------------------
    printSectionHeader ("Yes()");
    printf ("Please enter 'Y' > ");
    printf ("    Result: %d\n", yes ());
    printf ("Please enter 'y' > ");
    printf ("    Result: %d\n", yes ());
    printf ("Please enter 'N' > ");
    printf ("    Result: %d\n", yes ());
    printf ("Please enter 'yes', then 'no', then 'n' > ");
    printf ("    Result: %d\n", yes ());

    
    //--------------------------------------------------------
    printSectionHeader ("pause()"); // Displays the section header between the quotes and the pause function.
    pause (); // Calls the pause function.

    //--------------------------------------------------------
    printSectionHeader ("getInt()"); // Displays the section header between the quotes and getInt function.
    printf ("Enter 'ipc', then '144' > "); // Displays the output message between the quotes.
    tstInteger = getInt (); // Initializes tstInteger with the getInt function.
    printf ("    Integer entered: %d\n", tstInteger); // Prints the output message between the quotes and the variable tstInteger, adding a new line at the end.

    //--------------------------------------------------------
    printSectionHeader ("getIntInRange(int,int)"); // Displays the section header between the quotes and the getIntInRange function with the parameters being int and int.
    printf ("Enter 'seneca', then '99', then '501', then '250' > "); // Displays the output message between the quotes.
    tstInteger = getIntInRange (100, 500); // Initializes tstInteger with the getIntInRange function with the parameters being 100 (min) and 500 (max).
    printf ("    Integer entered: %d\n\n", tstInteger); // Displays the output message between the quotes and the variable tstInteger, adding two new lines at the end.
    printf ("Enter '100' > "); // Displays the output message between the quotes.
    tstInteger = getIntInRange (100, 500); // Initializes tstInteger with the getIntInRange function with the parameters being 100 (min) and 500 (max).
    printf ("    Integer entered: %d\n", tstInteger); // Displays the output message between the quotes and the variable tstInteger, adding two new lines at the end.
    printf ("Enter '500' > "); // Displays the output message between the quotes.
    tstInteger = getIntInRange (100, 500); // Initializes tstInteger with the getIntInRange function with the parameters being 100 (min) and 500 (max).
    printf ("    Integer entered: %d\n", tstInteger); // Displays the output message between the quotes and the variable tstInteger, adding two new lines at the end.

    //--------------------------------------------------------
    printSectionHeader ("getContact(struct Contact *)"); // Displays the section header between the quotes and the getContact function with the parameter being struct Contact *.
    getContact (&contact); // Passes by address (&contact) for getContact.
    printf ("\nValues Entered:\n"); // Displays the output message between the quotes, adding new lines at the end.
    printf ("Name: %s %s %s\n", contact.name.firstName, contact.name.middleInitial, contact.name.lastName);  // Displays the output message between the quotes and the variables contact.name.firstName, contact.name.middleInitial, and contact.name.lastName, adding a new line at the end.
    printf ("Address: %d|%s|%d|%s|%s\n", contact.address.streetNumber, contact.address.street, 
        contact.address.apartmentNumber, contact.address.postalCode, contact.address.city); // Displays the output message between the quotes and the variables contact.address.streetNumber, contact.address.street, contact.address.apartmentNumber, contact.address.postalCode, and contact.address.city, adding a new line at the end.
    printf ("Numbers: %s|%s|%s\n", contact.numbers.cell, contact.numbers.home, contact.numbers.business); // Displays the output message between the quotes and the variables contact.numbers.cell, contact.numbers.home, and contact.numbers.business, adding a new line at the end.

    //--------------------------------------------------------
    printSectionHeader ("contactManagerSystem()"); // Prints the section header between the quotes and the contactManagerSystem function.
    contactManagerSystem (); // Calls the contactManagerSystem function.

    //--------------------------------------------------------
    printSectionHeader ("Assign#2 - MS #2 test completed"); // Prints the section header between the quotes.

    return 0; // Returns the data back to the OS.
}

// The function printSectionHeader with no return type and has the parameter char as a const with the type of pointer being testName.
void printSectionHeader (const char* testName)
{
    printf ("\n"); // Prints a new line.
    printf ("------------------------------------------\n"); // Displays this output message, adding a new line at the end.
    printf ("Testing: %s\n", testName); // Displays this output message between the quotes and the variable testName, adding a new line at the end.
    printf ("------------------------------------------\n"); // Displays this output message, adding a new line at the end.
}