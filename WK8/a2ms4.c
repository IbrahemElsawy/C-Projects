/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 2: a2ms4.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/


#define _CRT_SECURE_NO_WARNINGS // Shows no warnings for the scanf lines when building the solution.

#include <stdio.h> // Includes the inputs/outputs of this program.
#include "contacts.h" // Includes the contacts header file, containing the structs and prototypes for the functions in contacts.c source file.
#include "contactHelpers.h" // Includes the contactHelpers header file, containing the prototypes for the functions in contactHelpers.c source file.

void printSectionHeader(const char* testName); // The prototype for the printSectionHeader function with no return type and has a parameter, which is testName.

// Starts the main function with an int return type being 0 (successful) and no parameters.
int main(void)
{
    printSectionHeader("Final A#2-Milestone #4"); // Prints the following header between the quotes.

    contactManagerSystem(); // Calls the contactManagerSystem function, which will do almost all of the work for the program.

    return 0; // Returns 0 when the program is successful.
}

// The printSectionHeader function with no return type and has a parameter, which is testName.
void printSectionHeader(const char* testName)
{
    printf("\n"); // Prints a new line.
    printf("------------------------------------------\n"); // Prints the following message between the quotes, adding a new line at the end.
    printf("Testing: %s\n", testName); // Prints the following message between the quotes and the variable testName, and adding a new line at the end.
    printf("------------------------------------------\n"); // Prints the following message between the quotes, adding a new line at the end.
}