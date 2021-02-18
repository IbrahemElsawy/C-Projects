/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 2: contactHelpers.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/


#define _CRT_SECURE_NO_WARNINGS // Defines no warnings for scanf lines when building the solution for the program.

#include "contactHelpers.h" // Includes the contactHelpers header file into this source file.

#include <stdio.h> // Includes the inputs/output facilities of this program.

// The clearKeyboard funtion that will have no return type and parameters.
void clearKeyboard (void)

{
	// A while loop for it the user inputs a character that is not new line (<enter> key).
	while (getchar () != '\n')   ;

}

// The pause function that will have no return type and parameters.
void pause (void)

{
	// Displays the output message, "(Press Enter to continue) " while calling the clearKeyboard function to flush the unncessary characters the user has inputted.
	printf ("(Press Enter to Continue)");
	clearKeyboard ();

}

// The getInt function with the return type being int and having no parameters.
int getInt (void)
 
{
	int value; // Declares value as an int variable.
	char NL = 'x'; // Declares NL as a char variable and initializes it to x.
	
	// The while loop for when NL is not equal to \n (new line) in terms of its condition.
	while (NL != '\n')
	{
		scanf ("%d", &value); // Accepts the user input of value and stores it as address of into memory.

		// The while loop for when value is equal to \n (new line) in terms of its condition.
		while (value == '\n')
		{

			clearKeyboard (); // Calls the clearKeyboard function to flush the unnecessary characters from the user input.
			printf ("*** INVALID INTEGER *** <Please enter an integer>: "); // Displays the output message between the quotes.
			scanf ("%d", &value); // Accepts the user input of value and stores it as address of into memory.
		
		}

		scanf ("%c", &NL); // Accepts the user input of NL and stores it as address of into memory.

		// The if statement for when NL is not equal to \n (new line) in terms of its condition.
		if (NL != '\n')
		{ 
			clearKeyboard (); // Calls the clearKeyboard function to flush the unnecessary characters from the user input.
			printf ("*** INVALID INTEGER *** <Please enter an integer>: "); // Displays the output message between the quotes.

		}

	}
				   
	// Returns the value variable.
	return value;
}

// The getIntRange function with the return type being int and the parameters being int, which are min and max.
int getIntInRange (int min, int max)
{
	// Declares value as an int variable and initializes it to getInt function (getInt();).
	int value;
	value = getInt();

	// The while loop for if the user input of int value from getInt function is less than the min value or greater than the max value.
	while (value < min || value > max)
	{ 
	// Displays the output message, "*** OUT OF RANGE *** <Enter a number between min and max>: " between the quotes and the variables min, max.
	printf ("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
	value = getInt (); // Initializes the value variable with getInt(), making the user have to input the correct int value within the range.

	}

	// Returns the value variable for this function.
	return value;

}

// The yes funtion with the return type being int and having no parameters.
int yes (void)
{
	int yes; // Declares yes as an int variable.
	char NL = 'x', ans = 'x'; // Declares NL and ans are char variables and initializes them to x.

	// The while loop for when NL is not equal to \n (new line) in terms of its condition.
	while (NL != '\n')
	{
		scanf ("%c", &ans); // Accepts the user input of ans and stores it as address of into memory.

		// The while loop for when ans is equal to \n (new line) in terms of its condition.
		while (ans == '\n')
		{
			
			clearKeyboard (); // Calls the clearKeyboard function to flush the unnecessary characters from the user input.
			printf ("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: "); // Displays this output message between the quotes.
			scanf ("%c", &ans); // Accepts user input of ans and stores it as address of into memory.

		}

		scanf ("%c", &NL); // Accepts user input of NL and stores it as address of into memory.

		// The if statement for when NL is not equal to \n (new line) in terms of its condition.
		if (NL != '\n')
		{
			clearKeyboard (); // Calls the clearKeyboard function to flush the unnecessary characters from the user input.
			printf ("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: "); // Displays this output message between the quotes.

		}

		// The else if statement for when ans is equal to Y or y in terms of its conditions.
		else if (ans == 'Y' || ans == 'y')
		{
		   yes = 1; // Assigns 1 to the yes variable.

		}

		// The else if statement for when ans is equal to N or n in terms of its conditions.
		else if (ans == 'N' || ans == 'n')
		{
		   yes = 0; // Assigns 0 to the yes variable.
		}

		// The else statement for when neither of the conditions above are met.
		else
		{
		   NL = 'x'; // Assigns x to NL.
		}
	}

	// Returns the yes variable.
	return yes;
}

// The menu function that has an int return type but no parameters.
int menu (void)
{
	// Declares value as an int variable.
	int value;

	// Displays the Contact Management System menu as output messages between the quotes and adding a new line at the end for each of them.
	printf ("Contact Management System\n");
	printf ("-------------------------\n");
	printf ("1. Display contacts\n");
	printf ("2. Add a contact\n");
	printf ("3. Update a contact\n");
	printf ("4. Delete a contact\n");
	printf ("5. Search contacts by cell phone number\n");
	printf ("6. Sort contacts by cell phone number\n");
	printf ("0. Exit\n");
	printf ("\n");

	printf ("Select an option:> "); // Displays the output message, asking the user to select an option.

	// Initializes the value variable with getIntInRange, having the parameters be 0 as the min and 6 as the max.
	value = getIntInRange (0, 6); 

	printf ("\n"); // Prints a new line.

	// Returns the value variable.
	return value;
}

// The contactManagerSystem function with no return type and parameters.
void contactManagerSystem (void)

{
	// Declares value and finished as int variables and initializes the finished variable with 0.
	int value;
	int finished = 0;

	// The while loop for if finished is equal to 0 in terms of its condition.
	while (finished == 0)
	{
		// Initializes value variable with menu function.
		value = menu ();

		// The switch cases with the condition being the value variable.
		switch (value)
		{

	    // Case 0 if the user inputted 0 as the value (option) for the menu function.
		case 0:

			printf ("Exit the program? (Y)es/(N)o: "); // Displays the output message, asking the user if they wish to exit the program.
			finished = yes (); // Initializes the finished variable with the yes function.
			break; // Breakes the switch case 0.

		// Case 1 if the user inputted 1 as the value (option) for the menu function.
		case 1:

			printf ("<<< Feature 1 is unavailable >>>\n\n"); // Displays this output message between the quotes, adding two new lines at the end.
			break; // Breaks the switch case 1.

		// Case 2 if the user inputted 2 as the value (option) for the menu function.
		case 2:

			printf ("<<< Feature 2 is unavailable >>>\n\n"); // Displays this output message between the quotes, adding two new lines at the end.
			break; // Breaks the switch case 2.

	    // Case 3 if the user inputted 3 as the value (option) for the menu function.
		case 3:

			printf ("<<< Feature 3 is unavailable >>>\n\n"); // Displays this output message between the quotes, adding two new lines at the end.
			break; // Breaks the switch case 3.

		// Case 4 if the user inputted 4 as the value (option) for the menu function.
		case 4:

			printf ("<<< Feature 4 is unavailable >>>\n\n"); // Displays this output message between the quotes, adding two new lines at the end.
			break; // Breaks the switch case 4.

		// Case 5 if the user inputted 5 as the value (option) for the menu function.
		case 5:

			printf ("<<< Feature 5 is unavailable >>>\n\n"); // Displays this output message between the quotes, adding two new lines at the end.
			break; // Breaks the switch case 5.

		// Case 6 if the user inputted 6 as the value (option) for the menu function.
		case 6:

			printf ("<<< Feature 6 is unavailable >>>\n\n"); // Displays this output message between the quotes, adding two new lines at the end.
			break; // Breaks the switch case 6.

		// The default case if the user inputted a value (option) that is not 0-6.
		default:

			break;

		}

		// The if statement for when the value is not equal to 0 in terms of its condition.
		if (value != 0)
		{
			// Calls the pause function.
			pause ();
		}

		// Prints a new line.
		printf ("\n");
	}

	printf ("Contact Management System: terminated\n"); // Displays this output message between the quotes, adding a new line at the end.
}

