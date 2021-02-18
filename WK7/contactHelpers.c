/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 1: contactHelpers.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/


#define _CRT_SECURE_NO_WARNINGS

#include "contactHelpers.h"

#include <stdio.h>

void clearKeyboard (void)

{
	while (getchar () != '\n')   ;

}

void pause (void)

{

	printf ("(Press Enter to continue) ");
	clearKeyboard ();

}


int getInt (void)

{
	int value;
	char NL = 'x';

	scanf ("%d%c", &value, &NL);

	
	while (NL != '\n')
	{
		clearKeyboard ();
		printf ("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf ("%d%c", &value, &NL);
	}

	return value;
}

int getIntInRange (int min, int max)
{

	int value = getInt();

	while (value < min || value > max)
	{ 

	printf ("*** OUT OF RANGE ** <Enter a number between %d and %d>: ", min, max);
	getInt ();

	}

	return value;

}


int yes (void)
{
	int yes;
	char NL = 'x', ans = 'x';


	while (NL != '\n')
	{
		scanf ("%c%c", &ans, &NL);

		if (NL != '\n')
		{
			clearKeyboard ();
			printf ("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");

		}
		
		else if (ans == 'Y' || ans == 'y')
		{
			yes = 1;

		}

		else if (ans == 'N' || ans == 'n')
		{
			yes = 0;
		}

		else
		{
			NL = 'x';
		}
	}

	return yes;
}


int menu (void)
{
	int value;
	
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

	printf ("Select an option:> ");

	value = getIntInRange (0, 6);

	return value;
}

void contactManagerSystem (void)

{
	int value;

	do
	{
		value = menu ();

		switch (value)
		{		

		case 0:

			printf ("Exit the program? (Y)es/(N)o: ");
			yes ();
			break;

		case 1:

			printf ("<<< Feature 1 is unavaliable >>>\n\n");
			pause ();
			break;

		case 2:

			printf ("<<< Feature 2 is unavaliable >>>\n\n");
			pause ();
			break;

		case 3:

			printf ("<<< Feature 3 is unavaliable >>>\n\n");
			pause ();
			break;

		case 4:

			printf ("<<< Feature 4 is unavaliable >>>\n\n");
			pause ();
			break;

		case 5:

			printf ("<<< Feature 5 is unavaliable >>>\n\n");
			pause ();
			break;

		case 6:

			printf ("<<< Feature 6 is unavaliable >>>\n\n");
			pause ();
			break;

		}  

	} while (value != 0);
}