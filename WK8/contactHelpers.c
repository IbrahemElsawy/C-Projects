/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) Assignment 2: contactHelpers.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/


#define _CRT_SECURE_NO_WARNINGS // Defines no warnings for scanf lines when building the solution for the program.

#define MAXCONTACTS 5 // Defines MAXCONTACTS as a const variable and sets its value to 5.

#include "contactHelpers.h" // Includes the contactHelpers header file into this source file.

#include <stdio.h> // Includes the inputs/output facilities of this program.

#include <string.h> // Includes the string library, containing functions like strcpy().

#include <ctype.h> // Includes several functions that are used for manipulating and analyzing characters, such as the isdigit() function.

// The clearKeyboard funtion that will have no return type and parameters.
void clearKeyboard(void)

{
	// A while loop for it the user inputs a character that is not new line (<enter> key).
	while (getchar() != '\n');

}

// The pause function that will have no return type and parameters.
void pause(void)

{
	// Displays the output message, "(Press Enter to continue) " while calling the clearKeyboard function to flush the unncessary characters the user has inputted.
	printf("(Press Enter to Continue)");
	clearKeyboard();

}

// The getInt function with the return type being int and having no parameters.
int getInt(void)

{
	int value; // Declares value as an int variable.
	char NL = 'x'; // Declares NL as a char variable and initializes it to x.

	// The while loop for when NL is not equal to \n (new line) in terms of its condition.
	while (NL != '\n')
	{
		scanf("%d", &value); // Accepts the user input of value and stores it as address of into memory.

		// The while loop for when value is equal to \n (new line) in terms of its condition.
		while (value == '\n')
		{

			clearKeyboard(); // Calls the clearKeyboard function to flush the unnecessary characters from the user input.
			printf("*** INVALID INTEGER *** <Please enter an integer>: "); // Displays the output message between the quotes.
			scanf("%d", &value); // Accepts the user input of value and stores it as address of into memory.

		}

		scanf("%c", &NL); // Accepts the user input of NL and stores it as address of into memory.

		// The if statement for when NL is not equal to \n (new line) in terms of its condition.
		if (NL != '\n')
		{
			clearKeyboard(); // Calls the clearKeyboard function to flush the unnecessary characters from the user input.
			printf("*** INVALID INTEGER *** <Please enter an integer>: "); // Displays the output message between the quotes.

		}

	}

	// Returns the value variable.
	return value;
}

// The getIntRange function with the return type being int and the parameters being int, which are min and max.
int getIntInRange(int min, int max)
{
	// Declares value as an int variable and initializes it to getInt function (getInt();).
	int value;
	value = getInt();

	// The while loop for if the user input of int value from getInt function is less than the min value or greater than the max value.
	while (value < min || value > max)
	{

		// Displays the output message, "*** OUT OF RANGE *** <Enter a number between min and max>: " between the quotes and the variables min, max.
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		value = getInt(); // Initializes the value variable with getInt(), making the user have to input the correct int value within the range.

	}

	// Returns the value variable for this function.
	return value;

}

// The yes funtion with the return type being int and having no parameters.
int yes(void)
{
	int yes; // Declares yes as an int variable.
	char NL = 'x', ans = 'x'; // Declares NL and ans are char variables and initializes them to x.

	// The while loop for when NL is not equal to \n (new line) in terms of its condition.
	while (NL != '\n')
	{
		scanf("%c", &ans); // Accepts the user input of ans and stores it as address of into memory.

		// The while loop for when ans is equal to \n (new line) in terms of its condition.
		while (ans == '\n')
		{

			clearKeyboard(); // Calls the clearKeyboard function to flush the unnecessary characters from the user input.
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: "); // Displays this output message between the quotes.
			scanf("%c", &ans); // Accepts user input of ans and stores it as address of into memory.

		}

		scanf("%c", &NL); // Accepts user input of NL and stores it as address of into memory.

		// The if statement for when NL is not equal to \n (new line) in terms of its condition.
		if (NL != '\n')
		{
			clearKeyboard(); // Calls the clearKeyboard function to flush the unnecessary characters from the user input.
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: "); // Displays this output message between the quotes.

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
int menu(void)
{
	// Declares value as an int variable.
	int value;

	// Displays the Contact Management System menu as output messages between the quotes and adding a new line at the end for each of them.
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");

	printf("Select an option:> "); // Displays the output message, asking the user to select an option.

	// Initializes the value variable with getIntInRange, having the parameters be 0 as the min and 6 as the max.
	value = getIntInRange(0, 6);

	printf("\n"); // Prints a new line.

	// Returns the value variable.
	return value;
}

// The contactManagerSystem function with no return type and parameters.
void contactManagerSystem(void)

{
	// Declares value and finished as int variables and initializes the finished variable with 0.
	int value;
	int finished = 0;
	

	// Creates an array of MAXCONTACTS for struct Contact contacts and initializes it to the following below.
	struct Contact contacts[MAXCONTACTS] = { { {"Rick", {'\0'}, "Grimes" },
		{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },
		{

			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } },
		{
			{ "Sasha", {'\0'}, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } },
	};



	// The while loop for if finished is equal to 0 in terms of its condition.
	while (finished == 0)
	{
		// Initializes value variable with menu function.
		value = menu();

		// The switch cases with the condition being the value variable.
		switch (value)
		{

			// Case 0 if the user inputted 0 as the value (option) for the menu function.
		case 0:

			printf("Exit the program? (Y)es/(N)o: "); // Displays the output message, asking the user if they wish to exit the program.
			finished = yes(); // Initializes the finished variable with the yes function.
			break; // Breakes the switch case 0.

		// Case 1 if the user inputted 1 as the value (option) for the menu function.
		case 1:

			displayContacts(contacts, MAXCONTACTS); // Calls the displayContacts function with the parameters being contacts and MAXCONTACTS.
			break; // Breaks the switch case 1.

		// Case 2 if the user inputted 2 as the value (option) for the menu function.
		case 2:

			addContact(contacts, MAXCONTACTS); // Calls the addContacts function with the parameters being contacts and MAXCONTACTS.
			break; // Breaks the switch case 2.

		// Case 3 if the user inputted 3 as the value (option) for the menu function.
		case 3:

			updateContact(contacts, MAXCONTACTS); // Calls the updateContact function with the parameters being contacts and MAXCONTACTS.
			break; // Breaks the switch case 3.

		// Case 4 if the user inputted 4 as the value (option) for the menu function.
		case 4:

			deleteContact(contacts, MAXCONTACTS); // Calls the deleteContact function with the parameters being contacts and MAXCONTACTS.
			break; // Breaks the switch case 4.

		// Case 5 if the user inputted 5 as the value (option) for the menu function.
		case 5:
			 
			searchContacts(contacts, MAXCONTACTS); // Calls the searchContacts function with the parameters being contacts and MAXCONTACTS.
			break; // Breaks the switch case 5.

		// Case 6 if the user inputted 6 as the value (option) for the menu function.
		case 6:

			sortContacts(contacts, MAXCONTACTS); // Calls the sortContacts function with the parameters being contacts and MAXCONTACTS.
			break; // Breaks the switch case 6.

		// The default case if the user inputted a value (option) that is not 0-6.
		default:

			break; // Breaks the default switch case.

		}

		// The if statement for when the value is not equal to 0 in terms of its condition.
		if (value != 0)
		{
			// Calls the pause function.
			pause();
		}

		// Prints a new line.
		printf("\n");
	}

	printf("Contact Management System: terminated\n"); // Displays this output message between the quotes, adding a new line at the end.
}

// The getTenDigitPhone function with no return type and has a parameter, which is phoneNum (has an allocated array of characters) and is declared as a char. 
void getTenDigitPhone(char phoneNum[])
{
	// Declares i and allDigits as int variables and intializes allDigits to 1.
	int i;
	int allDigits = 1;
	
	// The while loop for when allDigits is equal to 1 in terms of its condition.
	while (allDigits == 1)
	{
		phoneNum[10] = 0; // Assigns the parameter phoneNum with 10 characters (9 characters + 1 for the null terminator: '\0') and initializes it to 0.
		scanf("%11s", phoneNum); // Accepts the user input of phoneNum of up to 11 characters (9 characters + 1 for the null terminator: '\0') and stores it into memory.
		clearKeyboard(); // Calls the clearKeyboard function to flush unnecessary characters from the user input.

		// The if statement for when phoneNum is equal to 10 by returning a number of characters from the variable with the strlen() function in terms of its condition.
		if (strlen(phoneNum) == 10)
		{
			allDigits = 0; // Initializes allDigits to 0.

			// Starts the for loop that has the iteration i = 0, condition i < strlen(phoneNum), and change i++ within the parentheses. 
			for (i = 0; i < strlen(phoneNum); i++)
			{
				// The if statement for when the array of phoneNum with an index of i is not equal by using the isdigit() function to check if they are digits in terms of its condition.
				if (!isdigit(phoneNum[i]))
				{
					allDigits = 1; // Initializes allDigits to 1.
					printf("Enter a 10-digit phone number: "); // Prints the following message between the quotes.
				}
			}
		}

		// The else statement for when phoneNum is not equal to 10 by returning a number of characters from the variable with the strlen() function in terms of its condition.
		else
		{
			printf("Enter a 10-digit phone number: "); // Prints the following message between the quotes.
		}
	}
}

// The function searchContact that has a return type being int and has the parameters struct Contact (as a const) with the type of pointer being contacts (has an allocated array of characters), size being declared as an int, and cellNum (has an allocated array of characeters) being declared as a const char.
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i; // Declares i as an int variable.

	// Starts the for loop that has the iteration i = 0; condition i < size, and change i++ within the parentheses.
	for (i = 0; i < size; i++)
	{
		// The if statement for when contacts[i].numbers.cell and cellNum are the same by using the strcmp() function to compare them, along with the function being equal to 0 in terms of its condition.
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			return i; // Returns i as the return type.
		}
	}
		 return -1; // Returns -1 as the return type.

}

// The displayContactHeader that has no return type and no parameters.
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n"); // Prints the following message between the quotes, adding a new line at the end.

	printf("|                              Contacts Listing                               |\n"); // Prints the following message between the quotes, adding a new line at the end.

	printf("+-----------------------------------------------------------------------------+\n"); // Prints the following message between the quotes, adding a new line at the end.


}

// The displayContactFooter function with no return type and one parameter, which is count being declared as an int.
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n"); // Prints the following message between the quotes, adding a new line at the end.

	printf("Total contacts: %d\n\n", count); // Prints the following message between the quotes and the parameter count, adding two new lines at the end.

}

// The function displayContact that has no type and has the parameters struct Contact (as a const) with the type of pointer being contact.
void displayContact(const struct Contact* contact)
{
	printf(" %s ", contact->name.firstName); // Prints the following message between the quotes and the variable firstName from struct name that is from the parameter contact that it is pointing to (with a space after it in the message).

	// The if statement for when middleInitial from struct name that is from the parameter contact (with a * at the beginning of the condition) is not equal to 0 in terms of its condition.
	if (*contact->name.middleInitial != 0)
	{
		printf("%s ", contact->name.middleInitial); // Prints the following message between the quotes and the variable middleIntial from struct name that is from the parameter contact that it is pointing to (with a space after it in the message).

	}

	printf("%s\n", contact->name.lastName); // Prints the following message between the quotes and the variable lastName from struct name that is from the parameter contact that it is pointing to (with a space after it).


	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business); // Prints the following message between the quotes and the variables cell, numbers, and business from struct numbers that is from the parameter contact that it is pointing to (with spaces before, between, and after them, and having a qualifier each of displaying the strings left-justisfied in a field of 10 within the message).


	printf("       %d %s, ", contact->address.streetNumber, contact->address.street); // Prints the following message between the quotes and the variables streetNumber and street from struct address that is from the parameter contact that it is pointing to (with spaces before, between, and after them).

	// The if statement for when apartmentNumber from struct address that is from the parameter contact is greater than 0 in terms of its condition.
	if (contact->address.apartmentNumber > 0)
	{
		printf("Apt# %d, ", contact->address.apartmentNumber); // Prints the following message between the quotes and the variable apartmentNumber from struct address that is from the parameter contact that it is pointing to (with a space after the comma in the message).	
	}

	printf("%s, %s\n", contact->address.city, contact->address.postalCode); // Prints the following message between the quotes and the variables city and postalCode from struct address that is from the parameter contact that it is pointing to (with a space between them in the message).

}

// The function displayContacts that has no return type and has the parameters struct Contact (as a const) with the type of pointer being contacts (has an allocated array of characters), and size being declared as an int.
void displayContacts(const struct Contact contacts[], int size)
{
	// Declares i and count as int variables and initializes count to 0.
	int i;
	int count = 0;

	displayContactHeader(); // Calls the displayContactHeader function.

	// Starts the for loop that has the iteration i = 0; condition i < size, and change i++ within the parentheses.
	for (i = 0; i < size; i++)
	{
		// The if statement for when cell from struct numbers that is from the parameter contacts (with a * at the beginning of the condition) is greater than 0 in terms of its condition.
		if (*contacts[i].numbers.cell > 0)
		{

			displayContact(&contacts[i]); // Calls the displayContact function with a pass by address being an array of contacts (parameter) with an index of i.
			count++; // Increments the count variable by 1.
		}

	}

	displayContactFooter(count); // Calls the displayContactFooter function with count as the pass by value.

}

// The function searchContact that has no return type and has the parameters struct Contact (as a const) with the type of pointer being contacts (has an allocated array of characters), and size being declared as an int.
void searchContacts(const struct Contact contacts[], int size)
{
	char phone[12]; // Declares phone as a char variable and assigns it up to 12 characters (11 characters + 1 for the null terminator: '\0').
	int position; // Declares position as an int variable.

	printf("Enter the cell number for the contact: "); // Prints the following message between the quotes, asking the user to enter the cellphone number to find the contact.
	getTenDigitPhone(phone); // Calls the getTenDigitPhone function with phone as the pass by value.

	position = findContactIndex(contacts, size, phone); // Calls the findContactIndex (with contacts, size, and phone as the pass by values) and assigns it to position.

	// The if statement for when position is equal to -1 in terms of its condition.
	if (position == -1)
	{
		printf("*** Contact NOT FOUND ***\n"); // Prints the following message between the quotes, adding a new line at the end.

		printf("\n"); // Prints a new line.
	}

	// The else statement for when position is not equal to -1 in terms of its condition.
	else
	{
		printf("\n"); // Prints a new line.
		displayContact(&contacts[position]); // Calls the displayContact function with a pass by address that is an array of contacts (parameter) with position as the index.
		printf("\n"); // Prints a new line.
		
	}


}

// The function addContact that has no return type and has the parameters struct Contact with the type of pointer being contacts (has an allocated array of characters), and size being declared as an int.
void addContact(struct Contact contacts[], int size)
{
	// Declares i, empty, and full as int variables, and initializes empty and full to 0.
	int i;
	int empty = 0;
	int full = 0;

	// Starts the for loop that has the iteration i = 0; condition i < size, and change i++ within the parentheses.
	for (i = 0; i < size; i++)
	{
		// The if statement for when the strlen() function returns a certain number of characers for contacts[i].numbers.cell and if that function is equal to 0 in terms of its condition.
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			empty = i; // Assigns i to empty.
		}

		// The if statement for when the strlen() function returns a certain number of characers for contacts[i].numbers.cell and if that function is not equal to 0 in terms of its condition.
		else
		{
			full++; // Increments full by 1.
		}

	}

	// The if statement for when full is equal to size in terms of its condition.
	if (full == size)
	{
		
		printf("*** ERROR: The contact list is full! ***\n"); // Prints the following message between the quotes, adding a new line at the end.
		printf("\n"); // Prints a new line.

	}

	// The else statement for when full is not equal to size in terms of its condition.
	else
	{
		
		getContact(&contacts[empty]); // Calls the getContact function with a pass by address that is an array of contacts (parameter) with empty as the index.
		printf("--- New contact added! ---\n"); // Prints the following message between the quotes, adding a new line at the end.
		printf("\n"); // Prints a new line.
	}

}

// The function updateContact that has no return type and has the parameters struct Contact with the type of pointer being contacts(has an allocated array of characters), and size being declared as an int.
void updateContact(struct Contact contacts[], int size)
{

    int option; // Declares option as an int variable.
	char phone[12]; // Declares phone as a char variable and allocates its memory with up to 12 characters (11 characters + 1 for the null terminator: '\0').
	int update; // Declares update as an int variable.

	printf("Enter the cell number for the contact: "); // Prints the following message between the quotes, asking the user to enter the cellphone number to find the contact.
	getTenDigitPhone(phone); // Calls the getTenDigitPhone function with phone as the pass by value.
	update = findContactIndex(contacts, size, phone); // Calls the findContactIndex (with parameters contacts and size, and phone as the pass by values) and assigns it to update.

	// The if statement for when update is equal to -1 in terms of its condition.
	if (update == -1)
	{
		printf("*** Contact NOT FOUND ***\n"); // Prints the following message between the quotes, adding a new line at the end.
		printf("\n"); // Prints a new line.
	}

    // The else statement for when update is not equal to -1 in terms of its condition.
	else
	{
		printf("\n"); // Prints a new line.

		printf("Contact found:\n"); // Prints the following message between the quotes, adding a new line at the end.

		displayContact(&contacts[update]); // Calls the displayContact function with a pass by address of an array of contacts (parameter) with update as the index.

		printf("\n"); // Prints a new line.

		printf("Do you want to update the name? (y or n): "); // Prints the following message between the quotes, asking the user if they want to update the name or no.
		option = yes(); // Initializes option variable with the yes function that is being called, allowing the user to enter y or Y, or n or N.

		// The if statement for when option is equal to 1 in terms of its condition.
		if (option == 1)
		{
			getName(&contacts[update].name); // Calls the getName function with a pass by address that is an array of name from the parameter contacts with update as the index.
		}

		printf("Do you want to update the address? (y or n): "); // Prints the following message between the quotes, asking the user if they want to update the name or no.
		option = yes(); // Initializes option variable with the yes function that is being called, allowing the user to enter y or Y, or n or N.

		// The if statement for when option is equal to 1 in terms of its condition.
		if (option == 1)
		{
			getAddress(&contacts[update].address);  // Calls the getName function with a pass by address that is an array of address from the parameter contacts with update as the index.
		} 

		printf("Do you want to update the numbers? (y or n): "); // Prints the following message between the quotes, asking the user if they want to update the name or no.
		option = yes(); // Initializes option variable with the yes function that is being called, allowing the user to enter y or Y, or n or N.

		// The if statement for when option is equal to 1 in terms of its condition.
		if (option == 1)
		{
			getNumbers(&contacts[update].numbers); // Calls the getName function with a pass by address that is an array of numbers from the parameter contacts with update as the index.
		}

		printf("--- Contact Updated! ---\n"); // Prints the following message, adding a new line at the end.

		printf("\n"); // Prints a new line.

	}

		

		
}


// The function deleteContacts that has no return type and has the parameters struct Contact with the type of pointer being contacts (has an allocated array of characters), and size being declared as an int.
void deleteContact(struct Contact contacts[], int size)
{
	char phone[12]; // Declares phone as a char variable and allocates its memory with up to 12 characters (11 characters + 1 for the null terminator: '\0').
	int option; // Declares option as an int variable.
	int delete; // Declares delete as an int variable.
	
	printf("Enter the cell number for the contact: "); // Prints the following message between the quotes, asking the user to enter the cellphone number to find the contact. 
	getTenDigitPhone(phone); // Calls the getTenDigitPhone function with phone as the pass by value.
	delete = findContactIndex(contacts, size, phone); // Calls the findContactIndex (with parameters contacts and size, and phone as the pass by values) and assigns it to delete.

	// The if statement for when delete is equal to -1 in terms of its condition.
	if (delete == -1)
	{

		printf("*** Contact NOT FOUND ***\n"); // Prints the following message between the quotes, adding a new line at the end.

	}

	// The else statement for when delete is not equal to -1 in terms of its condition.
	else
	{
		printf("\n"); // Prints a new line.

		printf("Contact found:\n"); // Prints the following message between the quotes, adding a new line at the end.

		displayContact(&contacts[delete]); // Calls the displayContact function with a pass by address of an array of contacts (parameter) with delete as the index.

		printf("\n"); // Prints a new line.

		printf("CONFIRM: Delete this contact? (y or n): "); // Prints the following message between the quotes, asking the user if they want to delete this contact or not.
		option = yes(); // Initializes option variable with the yes function that is being called, allowing the user to enter y or Y, or n or N.

		// The if statement for when option is equal to 1 in terms of its condition.
		if (option == 1)
		{
			contacts[delete].numbers.cell[0] = '\0'; // Assigns the null terminator to the array of cell from struct numbers from the parameter contacts with delete as the index.
			contacts[delete].numbers.business[0] = '\0'; // Assigns the null terminator to the array of business from struct numbers from the parameter contacts with delete as the index.
			contacts[delete].numbers.home[0] = '\0'; // Assigns the null terminator to the array of home from struct numbers from the parameter contacts with delete as the index.
			
			printf("--- Contact deleted! ---\n"); // Prints the following message between the quotes, adding a new line at the end.
			
		}

		printf("\n"); // Prints a new line.
	}

}

// The function sortContacts that has no return type and has the parameters struct Contact with the type of pointer being contacts (has an allocated array of characters), and size being declared as an int.
void sortContacts(struct Contact contacts[], int size)
{
	// Declares i and j as int variables.
	int i;
	int j;

	struct Contact temp; // Creates an identifier to allocate its memory to struct Contact named temp.
	
	// Starts the for loop that has the iteration i = 0; condition i < size - 1, and change i++ within the parentheses.
	for (i = 0; i < size - 1; i++)
	{
		// Starts the for loop (within the for loop) that has the iteration j = 0; condition j < size, and change j++ within the parentheses.
		for (j = i + 1; j < size; j++)
		{

			// The if statement for when cell from struct numbers from the parameter contacts with an index of i is not equal to 0 by returning a number of characters with the strlen() function, and when cell from struct numbers from the parameter contacts with an index of i is not equal to 0 by returning a number of characters with the strlen() function in terms of its condition.
			if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[i].numbers.cell) != 0)
			{
				// The if statement for when cell from struct numbers from the parameter contacts with an index of i, and cell from struct numbers from the parameter contacts with an index of j is greater than 0 by using strcmp() function to compare them in terms of its condition.
				if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0)

				{

					temp = contacts[i]; // Assigns the array of contacts with an index of i to temp.
					contacts[i] = contacts[j]; // Assigns the array of contacts with an index of j to an array of contacts with an index of i.
					contacts[j] = temp; // Assigns temp to the array of contacts with an index of j.
				}
			}
		}
	}

	printf("--- Contacts sorted! ---\n"); // Prints the following message between the quotes, adding a new line at the end.

	printf("\n"); // Prints a new line.

}

