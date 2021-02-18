/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 2: contacts.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // Shows no warnings for the scanf lines when building the solution.
#include <stdio.h> // Includes the inputs/outputs of this program.
#include "contacts.h" // Includes the contacts header file, containing the structs and function prototypes.
#include "contactHelpers.h" // Includes the contactHelpers header file, containing the function prototypes from contactHelpers.c source file.

// The function getName that has no type and has the parameters struct FullName with the type of pointer being name.
void getName (struct FullName* name)
{  // Starts the getName function.

    //Declares yesOrNo as a char variable and initializes it with a null terminator.
    char yesOrNo = '\0';

    printf ("Please enter the contact's first name: "); // Displays the output message between the quotes, while telling the user to enter the contact's first name.
    scanf (" %[^\n]40s", name->firstName); // Accept's the user input (with qualifiers being in a field of 40) of name (type of pointer) and takes it on its left as well as firstName (identifier) on its right.
    clearKeyboard (); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

    printf ("Do you want to enter a middle initial(s)? (y or n): "); // Displays the output message between the quotes, while asking the user this question.
    yesOrNo = yes (); // Initializes yesOrNo variable with the yes function, allowing the user to enter y or Y, or n or N.

    // The if statement for when yesOrNo is equal to 1 (from the yes function in contactsHelpers.c).
    if (yesOrNo == 1)
    { 
        printf ("Please enter the contact's middle initial(s): "); // Displays the output message between the quotes, while telling the user to enter the contact's middle initial.
        scanf (" %6[^\n]", name->middleInitial); // Accepts the user's input (only allows up to 6 characters) of name (type of pointer) and takes it on its left as well as middleInitial (identifier) on its right.
        clearKeyboard (); // Calls the clearKeyboard function to flush unnecessary characters from the user input.
    }

   

    printf ("Please enter the contact's last name: "); // Displays the output message between the quotes, while telling the user to enter the contact's last name.
    scanf (" %[^\n]", name->lastName); // Accepts the user's input of name (type) and takes it on its left as well as lastName (identifier) on its right.
    clearKeyboard (); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

} // Ends the getName function.

// The function getAddress that has no type and has the parameters struct FullAddress with the type of pointer being address.
void getAddress (struct FullAddress* address)
{  //Starts the getAddress function.

    // Re-declares yesOrNo as a char variable and initializes it with a null terminator.
    char yesOrNo = '\0';

    // The do-while loop for streetNumber.
    do
    {
        // The if statement for when the user input of streetNumber to address is less than 1 and is greater or equal to 0 in terms of its conditions.
        if (address->streetNumber < 1 && address->streetNumber >= 0)
        {
            printf ("Please enter the contact's street number: "); // Displays the output message between the quotes, while telling the user to enter the contact's street number.
            address->streetNumber = getInt (); // Initializes the user input of streetNumber to address with getInt function.
        }

        // The if statement for when the user input of streetNumber to address is less than 0.
        if (address->streetNumber < 0)
        { 
            printf ("*** INVALID STREET NUMBER *** <must be a positive number>: "); // Displays the output message between the quotes, while telling the user to enter the contact's street number as a positive number.
            address->streetNumber = getInt ();  // Initializes the user input of streetNumber to address with getInt function.
        }
    } while (address->streetNumber < 1); // The while loop for when user input of streetNumber to address is less than 1 in terms of its condition.
    

    printf ("Please enter the contact's street name: "); // Displays the output message between the quotes, while telling the user to enter the contact's street name.
    scanf (" %[^\n]40s", address->street); // Accepts the user's input (with qualifiers in a field of 40) of address (type of pointer) and takes it on its left as well as streetName (identifier) on its right.
    clearKeyboard (); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

    printf ("Do you want to enter an apartment number? (y or n): "); // Displays the output message between the quotes, while asking the user this question.
    yesOrNo = yes (); // Initializes the yesOrNo variable with the yes function, allowing the user to enter y or Y, or n or N.


     // The if statement for when yesOrNo is equal to 1 (from the yes function in contactsHelpers.c).
    if (yesOrNo == 1)
    {
        // The do-while loop for apartmentNumber.
        do
        {
            // The if statement for when the user input of apartmentNumber to address is less than 1 and is greater or equal to 0 in terms of its conditions.
            if (address->apartmentNumber < 1 && address->apartmentNumber >= 0)
            {
                printf ("Please enter the contact's apartment number: "); // Displays the output message between the quotes, while telling the user to enter the contact's apartment number.
                address->apartmentNumber = getInt (); // Initializes the user input of apartmentNumber to address with getInt function.
            }
            // The if statement for when the user input of apartmentNumber to address is less than 1.
            if (address->apartmentNumber < 1)
            {
                printf ("*** INVALID APARTMENT NUMBER *** <must be a positive number>: "); // Displays the output message between the quotes, while telling the user to enter the contact's apartment number as a positive number.
                address->apartmentNumber = getInt (); // Initializes the user input of apartmentNumber to address with getInt function.
            }
        
        } while (address->apartmentNumber < 1); // The while loop for when user input of apartmentNumber to address is less than 1 in terms of its condition.
    
    }

    printf ("Please enter the contact's postal code: "); // Displays the output message between the quotes, while telling the user to enter the contact's postal code.
    scanf (" %7[^\n]", address->postalCode); // Accepts the user's input (with up to 7 characters) of address (type of pointer) and takes it on its left as well as postalCode (identifier) on its right.
    clearKeyboard (); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

    printf ("Please enter the contact's city: "); // Displays the output message between the quotes, while telling the user to enter the contact's city.
    scanf (" %[^\n]40s", address->city);// Accepts the user's input (with a qualifier in a field of 40) of address (type of pointer) and takes it on its left as well as cityName (identifier) on its right.
    clearKeyboard (); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

} // Ends the getAddress function.

// The function getNumbers that has no type and has the parameters struct FullNumbers with the type of pointer being numbers.
void getNumbers (struct FullNumbers* numbers)
{
    char yesOrNo = '\0';

    printf ("Please enter the contact's cell phone number: ");
    scanf (" %[^\n]", numbers->cell);

    printf ("Do you want to enter a home phone number? (y or n): "); // Displays the output message between the quotes, while asking the user this question.
    yesOrNo = yes ();  // Initializes the yesOrNo variable with the yes function, allowing the user to enter y or Y, or n or N.

     // The if statement for when yesOrNo is equal to 1 (from the yes function in contactsHelpers.c).
    if (yesOrNo == 1)
    {

        printf ("Please enter the contact's home phone number: "); // Displays the output message between the quotes, while telling the user to enter the contact's home phone number.
        scanf (" %[^\n]", numbers->home); // Accepts the user's input of numbers (type of pointer) and takes it on its left as well as homeNumber (identifier) on its right.
        clearKeyboard (); // Calls the clearKeyboard function to flush unnecessary characters from the user input.
    }

   

    printf ("Do you want to enter a business phone number? (y or n): "); // Displays the output message between the quotes, while asking the user this question.
    yesOrNo = yes (); // Initializes the yesOrNo variable with the yes function, allowing the user to enter y or Y, or n or N.

    // The if statement for when yesOrNo is equal to 1 (from the yes function in contactsHelpers.c).
    if (yesOrNo == 1)
    {
        printf ("Please enter the contact's business phone number: "); // Displays the output message between the quotes, while telling the user to enter the contact's business phone number.
        scanf (" %[^\n]", numbers->business); // Accepts the user's input of number (type of pointer) and takes it on its left as well as businessNumber (identifier) on its right.
        clearKeyboard (); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

    }
  

} // Ends the getNumbers function.

// The function getContact that has no return type and has the struct Contact with the type of pointer being contact.
void getContact (struct Contact* contact)

{

    getName (&contact->name); // Receives the user inputs of the variables from the type of pointer name and addresses as contact. 

    getAddress (&contact->address);  // Receives the user inputs of the variables from the type of pointer address and addresses as contact. 

    getNumbers (&contact->numbers); // Receives the user inputs of the variables from the type of pointer numbers and addresses as contact.


}
