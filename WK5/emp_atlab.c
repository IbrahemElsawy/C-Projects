/* Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) At Lab: emp_atlab.c

  Full Name: Ibrahem Elsawy
  Student ID: 157888199
  Student Email: ielsawy@myseneca.ca

*/

/*
Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) At Lab: emp_atlab.c

Full Name : Ibrahem Elsawy
Student ID : 157888199
Student Email : ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // Provides no warnings when testing it on the matrix server.
#define EMPLOYEENUMS 2 // Defines EMPLOYEESIZE variable as 2.
#include <stdio.h> // Provides the header file as well as input/output facilities of this program.


// Declare Struct Employee 




int main (void) // Starting the function of the program.

{
    // The derived type for Employee and its primitive type variables.
    struct Employee
    {
        int id;
        int age;
        double salary;
    };

    //The tag named employee that is going to be declared as a derived type (struct) with an array to the value of 0.
    struct Employee employee[EMPLOYEENUMS] = { {0} };

    // The int variables that are going to be declared in the program.
    int i;
    int options = 0;
    int employees = 0;

    // Displays what the program is going to be about.
    printf ("---=== EMPLOYEE DATA ===---\n");

    printf ("\n");

    // The do statement for the inputs, processing, and outputs of the program.
    do
    {
        // Displays what the options are for the user to choose in the program.
        printf ("1. Display Employee Information\n");
        printf ("2. Add Employee\n");
        printf ("0. Exit\n");

        printf ("\n");

        // Asks the user to select the above options, which they have to input either 1, 2, or 0.
        printf ("Please select from the above options: ");
        scanf ("%d", &options);
        printf ("\n");


        // The switch cases for the option 0, 1, and 2.
        switch (options)
        {

            // If the user has inputted 0 for the options.
        case 0:
            printf ("Exiting Employee Data Program. Good Bye!!!");
            printf ("\n");

            // Breaks the switch case for option 0 and ends the program.
            break;



            // If the user has inputted 1 for the options.
        case 1:

            // Displays what the the employee data is going to be shown under.
            printf ("EMP ID  EMP AGE EMP SALARY\n");
            printf ("======  ======= ==========\n");



            // Display what the employee data are within a for loop.
            for (i = 0; i < EMPLOYEENUMS; i++)
            {
                // If the employee id is greater than 0.
                if (employee[i].id > 0)
                {
                    // Displays the employee id, age, and salary data (only limited to 2 for this program).
                    printf ("%6d%9d%11.2lf", employee[i].id, employee[i].age, employee[i].salary);
                    printf ("\n");
                }
            }
            printf ("\n");

            // Breaks the switch case for option 1.
            break;


            // If the user has inputted 2 for the options.
        case 2:


            // Displays what the option is going to be revolving around.
            printf ("Adding Employee\n");
            printf ("===============\n");



            // If employees are less than EMPLOYEENUM size, it will display what the user has to input in terms of the employee ID, age, and salary.
            if (employees < EMPLOYEENUMS)
            {
                printf ("Enter Employee ID: ");
                scanf ("%d", &employee[employees].id);

                printf ("Enter Employee Age: ");
                scanf ("%d", &employee[employees].age);

                printf ("Enter Employee Salary: ");
                scanf ("%lf", &employee[employees].salary);

                printf ("\n");
                employees++;
            }

            //The else statement for if the maximum number of employees have been reached.
            else
            {
                printf ("ERROR!!! Maximum Number of Employees Reached\n");
                printf ("\n");
            }

            // Breaks the switch case for the if and else statements for option 2.
            break;

            // The default case for if the user has inputted an option other than 0, 1, and 2.
            default:
            printf ("ERROR: Incorrect Option: Try Again\n");
            printf ("\n");
        }

      // The while loop for if the user has not inputted option 0.
    } while (options != 0);


    return 0; // Returns the codes back to the OS.

}



