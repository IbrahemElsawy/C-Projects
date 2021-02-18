/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 1: contacts.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // Shows no warnings for the scanf lines when building the solution.
#include <stdio.h> // Includes the inputs/outputs of this program.
#include "contacts.h" // Includes the header file, "contacts.h" that contains the structs and function prototypes.

// The function getName that has no type and has the parameters struct FullName with the type of pointer being name.
void getFullName (struct FullName* name)
{  // Starts the getName function.

    //Declares yesOrNo as a char variable and initializes it with a null terminator.
    char yesOrNo = '\0';

    printf ("Please enter the contact's first name: "); // Prints the output message between the quotes, while telling the user to enter the contact's first name.
    scanf (" %[^\n]", name->firstName); // Accept's the user input of name (type of pointer) and takes it on its left as well as firstName (identifier) on its right.

    printf ("Do you want to enter a middle initial(s)? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    scanf (" %c%*c", &yesOrNo); // Accepts the user's input of yesOrNo and stores it as address of into memory.

    //The if statement for when yesOrNo equals to y or Y in terms of its conditions.
    if (yesOrNo == 'y' || yesOrNo == 'Y')
    {

        printf ("Please enter the contact's middle initial(s): "); // Prints the output message between the quotes, while telling the user to enter the contact's middle initial.
        scanf (" %[^\n]", name->middleInitial); // Accepts the user's input of name (type of pointer) and takes it on its left as well as middleInitial (identifier) on its right.


    } // Ends the if statement.

    printf ("Please enter the contact's last name: "); // Prints the output message between the quotes, while telling the user to enter the contact's last name.
    scanf (" %[^\n]", name->lastName); // Accepts the user's input of name (type) and takes it on its left as well as lastName (identifier) on its right.

} // Ends the getName function.

// The function FullAddress that has no type and has the parameters struct FullAddress with the type of pointer being address.
void getFullAddress (struct FullAddress* address)
{  //Starts the getAddress function.

    // Re-declares yesOrNo as a char variable and initializes it with a null terminator.
    char yesOrNo = '\0';

    // Starts the do-while loop when the user inputs the contact's street number.
    do
    {
        printf ("Please enter the contact's street number: "); // Prints the output message between the quotes, while telling the user to enter the contact's street number.
        scanf ("%d%*c", &address->streetNumber); // Accepts the user's input of address (type of pointer) and takes it on its left as well as streetNumber (identifier) on its right.

    } while (address->streetNumber < 1); // The while loop that loops for when the condition address->streetNumber < 1 has been met.
    // Ends the do-while loop.

    printf ("Please enter the contact's street name: "); // Prints the output message between the quotes, while telling the user to enter the contact's street name.
    scanf ("%[^\n]", address->streetName); // Accepts the user's input of address (type of pointer) and takes it on its left as well as streetName (identifier) on its right.

    printf ("Do you want to enter an apartment number? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    scanf (" %c%*c", &yesOrNo); // Accepts the user's input of yesOrNo and stores it as address of into memory.

    // The if statement for when yesOrNo equals to y or Y in terms of its conditions.
    if (yesOrNo == 'y' || yesOrNo == 'Y')
    {   // Starts the if statement.

        // Starts the do-while loop within the if statement.
        do
        {
            printf ("Please enter the contact's apartment number: "); // Prints the output message between the quotes, while telling the user to enter the contact's apartment number.
            scanf ("%d%*c", &address->apartmentNumber); // Accepts the user's input of address (type of pointer) and takes it on its left as well as apartmentNumber (identifier) on its right.

        } while (address->apartmentNumber < 1); // The while loop that loops for when the condition address->apartmentNumber < 1 has been met.
        // Ends the do-while loop within the if statement.

    } // Ends the if statement.

    printf ("Please enter the contact's postal code: "); // Prints the output message between the quotes, while telling the user to enter the contact's postal code.
    scanf (" %[^\n]", address->postalCode); // Accepts the user's input of address (type of pointer) and takes it on its left as well as postalCode (identifier) on its right.

    printf ("Please enter the contact's city: "); // Prints the output message between the quotes, while telling the user to enter the contact's city.
    scanf (" %[^\n]", address->cityName); // Accepts the user's input of address (type of pointer) and takes it on its left as well as cityName (identifier) on its right.

} // Ends the getAddress function.

// The function getNumbers that has no type and has the parameters struct FullNumbers with the type of pointer being numbers.
void getFullNumbers (struct FullNumbers* numbers)
{ // Starts the getNumbers function.

    // Redeclares yesOrNo as a char variable again and initializes it with a null terminator.
    char yesOrNo = '\0';

    printf ("Do you want to enter a cell phone number? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    scanf (" %c", &yesOrNo); // Accepts the user's input of yesOrNo and stores it as address of into memory.

    // The if statement for when yesOrNo equals to y or Y in terms of its conditions.
    if (yesOrNo == 'y' || yesOrNo == 'Y')
    {  // Starts the if statement.

        printf ("Please enter the contact's cell phone number: "); // Prints the output message between the quotes, while telling the user to enter the contact's cell phone number.
        scanf (" %[^\n]", numbers->cellNumber); // Accepts the user's input of numbers (type of pointer) and takes it on its left as well as cellNumber (identifier) on its right.

    } // Ends the if statement.

    printf ("Do you want to enter a home phone number? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    scanf (" %c%*c", &yesOrNo); // Accepts the user's input of yesOrNo and stores it as address of into memory.

    // The if statement for when yesOrNo is equal to y and Y in terms of its conditions.
    if (yesOrNo == 'y' || yesOrNo == 'Y')
    {  // Starts the if statement.

        printf ("Please enter the contact's home phone number: "); // Prints the output message between the quotes, while telling the user to enter the contact's home phone number.
        scanf (" %[^\n]", numbers->homeNumber); // Accepts the user's input of numbers (type of pointer) and takes it on its left as well as homeNumber (identifier) on its right.

    } // Ends the if statement.


    printf ("Do you want to enter a business phone number? (y or n): "); // Prints the output message between the quotes, while asking the user this question.
    scanf (" %c%*c", &yesOrNo); // Accepts the user's input of yesOrNo and stores it as address of into memory.

    // The if statement for when yesOrNo equals to y or Y in terms of its conditions.
    if (yesOrNo == 'y' || yesOrNo == 'Y')
    {
        printf ("Please enter the contact's business phone number: "); // Prints the output message between the quotes, while telling the user to enter the contact's business phone number.
        scanf (" %[^\n]", numbers->businessNumber); // Accepts the user's input of number (type of pointer) and takes it on its left as well as businessNumber (identifier) on its right.
    }
} // Ends the getNumbers function.

getContact (void)

{




}
