/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 2: contacts.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // Shows no warnings for the scanf lines when building the solution.
#include <stdio.h> // Includes the inputs/outputs of this program.
#include "contacts.h" // Includes the contacts header file, containing the structs and prototypes of the functions in this source file.
#include "contactHelpers.h" // Includes the contactHelpers header file, containing the prototypes for the functions in the contactHelpers.c source file.
#include <string.h> // Includes the string library, containing functions like strcpy().

// The function getName that has no type and has the parameters struct FullName with the type of pointer being name.
void getName(struct FullName* name)
{  

    //Declares yesOrNo as a char variable and initializes it with a null terminator.
    char yesOrNo = '\0';

    printf("Please enter the contact's first name: "); // Prints the output message between the quotes, while telling the user to enter the contact's first name.
    scanf(" %[^\n]40s", name->firstName); // Accept's the user input (with qualifiers being in a field of 40) of firstName from struct name that it is pointing to and stores it into memory.
    clearKeyboard(); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

    printf("Do you want to enter a middle initial(s)? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    yesOrNo = yes(); // Initializes yesOrNo variable with the yes function that is being called, allowing the user to enter y or Y, or n or N.

    // The if statement for when yesOrNo is equal to 1 (from the yes function in contactHelpers.c) in terms of its condition.
    if (yesOrNo == 1)
    {
        printf("Please enter the contact's middle initial(s): "); // Prints the output message between the quotes, while telling the user to enter the contact's middle initial.
        scanf(" %6[^\n]", name->middleInitial); // Accepts the user's input (only allows up to 6 characters) of middleInitial from struct name that it is pointing to and stores it into memory.
        clearKeyboard(); // Calls the clearKeyboard function to flush unnecessary characters from the user input.
    }

    //The else statement for when yesOrNo is not equal to 1 (from the yes function in contactHelpers.c) in terms of its condition.
    else
    {

        strcpy(name->middleInitial, "\0"); // Copies the user's input of middleInitial from struct name that it is pointing to the null terminator.
    }

    printf("Please enter the contact's last name: "); // Prints the output message between the quotes, while telling the user to enter the contact's last name.
    scanf(" %[^\n]", name->lastName); // Accepts the user's input of lastName from struct name that it is pointing to and stores it into memory.
    clearKeyboard(); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

} 

// The function getAddress that has no type and has the parameters struct FullAddress with the type of pointer being address.
void getAddress(struct FullAddress* address)
{  

    // Re-declares yesOrNo as a char variable and initializes it with a null terminator.
    char yesOrNo = '\0';

    printf("Please enter the contact's street number: "); // Prints the output message between the quotes, while telling the user to enter the contact's street number.
    address->streetNumber = getInt(); // Initializes the user input of streetNumber from struct address that it is pointing to with the getInt function that is being called.
    
    // The while loop for when the user input of streetNumber from struct address that it is pointing to is less than 0 in terms of its condition.
    while (address->streetNumber < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: "); // Prints the output message between the quotes, while telling the user to enter the contact's street number as a positive number.
        address->streetNumber = getInt();  // Initializes the user input of streetNumber from struct address that it is pointing to with the getInt function that is being called.

    }



    printf("Please enter the contact's street name: "); // Prints the output message between the quotes, while telling the user to enter the contact's street name.
    scanf(" %[^\n]", address->street); // Accepts the user's input of street from struct address that it is pointing to and stores it into memory.
    clearKeyboard(); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

    printf("Do you want to enter an apartment number? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    yesOrNo = yes(); // Initializes the yesOrNo variable with the yes function that is being called, allowing the user to enter y or Y, or n or N.


     // The if statement for when yesOrNo is equal to 1 (from the yes function in contactsHelpers.c) in terms of its condition.
    if (yesOrNo == 1)
    {
        // The do-while loop for apartmentNumber.
        do
        {
            // The if statement for when the user input of apartmentNumber from struct address that is pointing to is less than 1 and is greater or equal to 0 in terms of its conditions.
            if (address->apartmentNumber < 1 && address->apartmentNumber >= 0)
            {
                printf("Please enter the contact's apartment number: "); // Prints the output message between the quotes, while telling the user to enter the contact's apartment number.
                address->apartmentNumber = getInt(); // Initializes the user input of apartmentNumber from struct address that it is pointing to with getInt function being called.
            }
            // The if statement for when the user input of apartmentNumber from struct address is less than 1.
            if (address->apartmentNumber < 1)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: "); // Prints the output message between the quotes, while telling the user to enter the contact's apartment number as a positive number.
                address->apartmentNumber = getInt(); // Initializes the user input of apartmentNumber from struct address that it is pointing to with getInt function being called.
            }

        } while (address->apartmentNumber < 1); // The while loop for when user input of apartmentNumber from struct address that it is pointing to is less than 1 in terms of its condition.

    }

    printf("Please enter the contact's postal code: "); // Prints the output message between the quotes, while telling the user to enter the contact's postal code.
    scanf(" %7[^\n]", address->postalCode); // Accepts the user's input (with up to 7 characters) of postalCode from struct address that it is pointing to and stores it into memory.
    clearKeyboard(); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

    printf("Please enter the contact's city: "); // Prints the output message between the quotes, while telling the user to enter the contact's city.
    scanf(" %[^\n]40s", address->city);// Accepts the user's input (with a qualifier in a field of 40) of city from struct address that it is pointing to and stores it into memory.
    clearKeyboard(); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

} 

// The function getNumbers that has no type and has the parameters struct FullNumbers with the type of pointer being numbers.
void getNumbers(struct FullNumbers* numbers)
{
    // Re-declares yesOrNo as a char variable and initializes it with a null terminator.
    char yesOrNo = '\0';

    printf("Please enter the contact's cell phone number: "); // Prints the output message between the quotes, while telling the user to enter the contact's cell phone number.
    getTenDigitPhone(numbers->cell); // Calls the getTenDigitPhone function with receiving the user input of cell from struct numbers that it is pointing to and stores it into memory.

    printf("Do you want to enter a home phone number? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    yesOrNo = yes();  // Initializes the yesOrNo variable with the yes function being called, allowing the user to enter y or Y, or n or N.

     // The if statement for when yesOrNo is equal to 1 (from the yes function in contactsHelpers.c) in terms of its condition.
    if (yesOrNo == 1)
    {

        printf("Please enter the contact's home phone number: "); // Prints the output message between the quotes, while telling the user to enter the contact's home phone number.
        getTenDigitPhone(numbers->home); // Calls the getTenDigitPhone function with receiving the user input of home from struct numbers that it is pointing to and stores it into memory.
    }

    // The else statement for when yesOrNo is not equal to 1 (from the yes function in contactsHelpers.c) in terms of its condition.
    else
    {

        strcpy(numbers->home, "\0"); // Copies the null terminator to the user's input of home from struct numbers that it is pointing to with the strcmp function.

    }


    printf("Do you want to enter a business phone number? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    yesOrNo = yes(); // Initializes the yesOrNo variable with the yes function being called, allowing the user to enter y or Y, or n or N.

    // The if statement for when yesOrNo is equal to 1 (from the yes function in contactsHelpers.c) in terms of its condition.
    if (yesOrNo == 1)
    {
        printf("Please enter the contact's business phone number: "); // Prints the output message between the quotes, while telling the user to enter the contact's business phone number.
        getTenDigitPhone(numbers->business); // Calls the getTenDigitPhone function with receiving the user input of business from struct numbers that it is pointing to and stores it into memory.

    }

    // The else statement for when yesOrNo is not equal to 1 (from the yes funtion in contactsHelpers.c) in terms of its condition.
    else
    {
        strcpy(numbers->business, "\0"); // Copies the null terminator to the user's input of business from struct numbers that it is pointing to with the strcpy() function.
    }


} 

// The function getContact that has no return type and has the struct Contact with the type of pointer being contact.
void getContact(struct Contact* contact)
{

    getName(&contact->name); // Receives the user inputs of the variables from the type of pointer name and addresses as contact. 

    getAddress(&contact->address);  // Receives the user inputs of the variables from the type of pointer address and addresses as contact. 

    getNumbers(&contact->numbers); // Receives the user inputs of the variables from the type of pointer numbers and addresses as contact.

}