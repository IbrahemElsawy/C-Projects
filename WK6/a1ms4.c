/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 1: a1ms4.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // Shows no warnings for the scanf lines when building the solution.
#include <stdio.h> // Includes the inputs/outputs of this program.
#include "contacts.h" // Includes the header file, "contacts.h" that includes the structs and function prototypes.

// The main function with a return type (int) and has no parameters (void).
int main (void)

{ // Starts the main function.

    // Intiailizes a range of values ( { { { 0  } } } ) for struct Contact named contact.
    struct Contact contact = { { { 0 } } };

    printf ("Contact Management System\n"); // Prints the output message betwen the quotes, adding a new line at the end.
    printf ("=========================\n"); // Prints the output message between the quotes, adding a new line at the end.

    getFullName (&contact.name); // Receives the user inputs of the variables from the type of pointer name and addresses as contact. 

    getFullAddress (&contact.address);  // Receives the user inputs of the variables from the type of pointer address and addresses as contact. 

    getFullNumbers (&contact.numbers); // Receives the user inputs of the variables from the type of pointer numbers and addresses as contact.

    printf ("\n");  // Adds a new line.
    printf ("Contact Details\n"); // Prints the output message between the quotes, adding a new line at the end.
    printf ("===============\n"); // Prints the output message between the quotes, adding a new line at the end.
    printf ("Name Details\n"); // Prints the output message between the quotes, adding a new line at the end.
    printf ("------------\n"); // Prints the output message between the quotes, adding a new line at the end.
    printf ("First name: %s\n", contact.name.firstName); // Prints the output message of what the contact's first name is between the quotes and the variable contact.name.firstName (adds a new line at the end).
    printf ("Middle initial(s): %s\n", contact.name.middleInitial); // Prints the output message of what the contact's middle initial(s) is between the quotes and the variable contact.name.middleInitial (adds a new line at the end).
    printf ("Last name: %s\n\n", contact.name.lastName); // Prints the output message of what the contact's last name is between the quotes and the variable contact.name.lastName (adds a new line at the end).

    printf ("Address Details\n"); // Prints the output message between the quotes, adding a new line at the end,
    printf ("---------------\n"); // Prints the output message between the quotes, adding a new line at the end.
    printf ("Street number: %d\n", contact.address.streetNumber); // Prints the output message of what the contact's city is between the quotes and the variable contact.address.city (adds a new line at the end).
    printf ("Street name: %s\n", contact.address.streetName); // Prints the output message of what the contact's city is between the quotes and the variable contact.address.city (adds a new line at the end).
    printf ("Apartment: %d\n", contact.address.apartmentNumber); // Prints the output message of what the contact's city is between the quotes and the variable contact.address.city (adds a new line at the end).
    printf ("Postal code: %s\n", contact.address.postalCode); // Prints the output message of what the contact's city is between the quotes and the variable contact.address.city (adds a new line at the end).
    printf ("City: %s\n\n", contact.address.cityName); // Prints the output message of what the contact's city is between the quotes and the variable contact.address.city (adds a new line at the end).

    printf ("Phone Numbers\n"); // Prints the output message of what the phone numbers are between the quotes, adding a new line at the end.
    printf ("-------------\n"); // Prints the output message between the quotes, adding a new line at the end.
    printf ("Cell phone number: %s\n", contact.numbers.cellNumber); // Prints the output message of what the contact's cell phone number is between the quotes and the variable contact.numbers.cell (adds a new line at the end).
    printf ("Home phone number: %s\n", contact.numbers.homeNumber); // Prints the output message of what the contact's home phone number is between the quotes and the variable contact.numbers.home (adds a new line at the end).
    printf ("Business phone number: %s\n\n", contact.numbers.businessNumber); // Prints the output message of what the contact's business phone number between the quotes and the variable contact.numbers.address (adds a new line at the end).

    
    printf ("Structure test for Contact using functions done!\n"); // Prints the output message that the program has been successfully completed.

    return 0; // Returns the data back to the OS.

} // Ends the main function.