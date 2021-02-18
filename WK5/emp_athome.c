/* Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) At Home: emp_inhome.c

  Full Name: Ibrahem Elsawy
  Student ID: 157888199
  Student Email: ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // Provides no warnings when testing it on the matrix server.
#define EMPLOYEENUMS 4 // Defines EMPLOYEESIZE variable as 2.
#include <stdio.h> // Provides the header file as well as input/output facilities of this program.


int main (void) // Starting the function of the program.

{
    // The struct Employee and its primitive type variables.
    struct Employee
    {
        int id;
        int age;
        double salary;
    };

    //The tag named employee that is going to be declared as a derived type (struct) with an array to the value of 0 in a safe place.
    struct Employee employee[EMPLOYEENUMS] = { {0} };

    // The int variables that are going to be declared in the program with an initial value of 0.
    int i;
    int options = 0;
    int employees = 0;
    int indexOfEmployeeToBeAdded = 0;
    int empIdToChange = 0;
    int indexOfEmployeeToBeChanged = 0;
    int employeeToRemove = 0;
    int indexOfEmployeeToBeRemoved = 0;

    // Displays what the program is going to be about.
    printf ("---=== EMPLOYEE DATA ===---\n");

    printf ("\n");

    // The do statement for the inputs, processing, and outputs of the program.
    do
    {
        // Displays what the options are for the user to choose in the program.
        printf ("1. Display Employee Information\n");
        printf ("2. Add Employee\n");
        printf ("3. Update Employee Salary\n");
        printf ("4. Remove Employee\n");
        printf ("0. Exit\n");

        printf ("\n");

        // Asks the user to select the above options, which they have to input either 1, 2, 3, 4, or 0.
        printf ("Please select from the above options: ");
        scanf ("%d", &options);
        printf ("\n");


        // The switch cases for the option 0, 1, 2, 3, and 4.
        switch (options)
        {

        // If the user has prompted 0 for the options.
        case 0:
            printf ("Exiting Employee Data Program. Good Bye!!!");
            printf ("\n");

            // Breaks the switch case for prompt 0 and ends the program.
            break;



        // If the user has prompted 1 from the options.
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
                    // Displays the employee id, age, and salary data (only limited to 4 for this program).
                    printf ("%6d%9d%11.2lf", employee[i].id, employee[i].age, employee[i].salary);
                    printf ("\n");
                }
            }
            printf ("\n");

            // Breaks the switch case for prompt 1.
            break;


        // If the user has prompted 2 from the options.
        case 2:

            
            // Displays what the prompt is going to be revolving around.
            printf ("Adding Employee\n");
            printf ("===============\n");

            // Declares foundEmployeeId with an initial value of 0.
            int foundEmployeeId = 0;

            // The for loop with the initialization, condition, and increment for when the user adds employees.
            for (i = 0; i < EMPLOYEENUMS; i++)
            {
                // The if statement for if the employee id with an index of i is equal to 0.
                if (employee[i].id == 0)
                {
                    // The calculations to find the employee id and store it to the list of employee data in prompt 1. 
                    foundEmployeeId = 1;
                    indexOfEmployeeToBeAdded = i;
                    // Breaks the the if statement.
                    break;
                }
            }

            // The if statement for when the user has already added 5 employees and wants to add another employee again.
            if (foundEmployeeId == 0)
            {

                // Displays how the maximmum number of employees has been reached.
                printf ("ERROR!!! Maximum Number of Employees Reached\n");
                printf ("\n");

            }

            // The else statement with what the user should input in terms of the employee id, age, and salary.
            else
            {
                printf ("Enter Employee ID: ");
                scanf ("%d", &employee[indexOfEmployeeToBeAdded].id);


                printf ("Enter Employee Age: ");
                scanf ("%d", &employee[indexOfEmployeeToBeAdded].age);


                printf ("Enter Employee Salary: ");
                scanf ("%lf", &employee[indexOfEmployeeToBeAdded].salary);


                printf ("\n");

                // Increments the employees variable.
                employees++;
            }


            // Breaks the switch case for the if and else statements for prompt 2.
            break;

   
        // If the user has prompted 3 from the options.
        case 3:

            // Declares foundEmployeeId with an initial value of 0.
            foundEmployeeId = 0;

            // Displays what the prompt is going to be about.
            printf ("Update Employee Salary\n");
            printf ("======================\n");

            // Tells the user to input the employee id that they wish to update in terms of the salary.
            printf ("Enter Employee ID: ");
            scanf ("%d", &empIdToChange);

            //The do-while loop for after the user has inputted the employee id.
            do
            {
                // The for loop with the initialization, condition, and increment for when the user updates an employee's salary.
                for (i = 0; i < EMPLOYEENUMS; i++)
                {
                    // The if statement for if the empIdToChange is equal to employee.id with an index of i.
                    if (empIdToChange == employee[i].id)
                    {
                        // The calculations to find the employee id and change that employee's salary to an updated one.
                        foundEmployeeId = 1;
                        indexOfEmployeeToBeChanged = i;
                        // Breaks the if statement.
                        break;
                    }
                }
                // The if statement for when the foundEmployeeId is equal to 0.
                if (foundEmployeeId == 0)
                {
                    // Displays how the employee id has not been found and asks the user to enter the correct employee id.
                    printf ("*** ERROR: Employee ID not found! ***");
                    printf ("\nEnter Employee ID: ");
                    scanf ("%d", &empIdToChange);
                    
                }

              // The while loop for if the employee id has not been found (foundEmployeeId is equal to 0 for the condition).
            } while (foundEmployeeId == 0);

            // Displays what that employee's current salary is.
            printf ("The current salary is %.2lf\n", employee[indexOfEmployeeToBeChanged].salary);
            
            // Asks the user to enter that employee's new salary.
            printf ("Enter Employee New Salary: ");
            scanf ("%lf", &employee[indexOfEmployeeToBeChanged].salary);
            printf ("\n");

            // Breaks the switch case for the for, if and else, and while loop for prompt 3.
            break;
        
        // If the user has prompted 4 from the options.
        case 4:

            // Declares foundEmployeeId with an initial value of 0.
            foundEmployeeId = 0;

            //Displays what the prompt is going to be about.
            printf ("Remove Employee\n");
            printf ("===============\n");
            
            // Tells the user to input the employee id that they wish to remove.
            printf ("Enter Employee ID: ");
            scanf ("%d", &employeeToRemove);

            //The do-while loop for after the user has inputted the employee id.
            do
            {
                // The for loop with the initialization, condition, and increment for when the user removes the employee from the list of employees in prompt 1.
                for (i = 0; i < EMPLOYEENUMS; i++)
                {
                    // The if statement for if the empIdToChange is equal to employee.id with an index of i.
                    if (employeeToRemove == employee[i].id)
                    {
                        // The calculations to find the employee id and remove it from the list of employees in prompt 1.
                        foundEmployeeId = 1;
                        indexOfEmployeeToBeRemoved = i;
                        // Breaks the if statement.
                        break;
                    }
                }
                // The if statement for when the foundEmployeeId is equal to 0.
                if (foundEmployeeId == 0)
                {
                    // Displays how the employee id has not been found and asks the user to enter the correct employee id.
                    printf ("*** ERROR: Employee ID not found! ***");
                    printf ("\nEnter Employee ID: ");
                    scanf ("%d", &employeeToRemove);
                    
                }

              // The while loop for if the employee id has not been found (foundEmployeeId is equal to 0 for the condition).
            } while (foundEmployeeId == 0);

            // Displays which employee will be removed regarding their data (e.g. age and salary).
            printf ("Employee %d will be removed\n", employee[indexOfEmployeeToBeRemoved].id);
            printf ("\n");
            // Sets the employee.id variable to the value of 0 with an index of indexOfEmployeeToBeRemoved in it.
            employee[indexOfEmployeeToBeRemoved].id = 0;
            // Decrements the employees variables.
            employees--;
            
            // Breaks the switch case for the for, if and else, and while loop for prompt 4.
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


