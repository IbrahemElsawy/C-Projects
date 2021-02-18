/* Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) At Lab: Temperature

  Full Name: Ibrahem Elsawy
  Student ID: 157888199
  Student Email: ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // It displays no warnings when testing it in matrix.
#define NUMS 3 // It defines the NUMS variable as 3.
#include <stdio.h> // Provides the header file as well as input/output facilities of this program.

int main (void) // Starting the function of the program.

{                   // To start the body of the program.

    // The int and float variables that will be declared as 0 for this program.
    int i, high = 0, low = 0;
    float average = 0;

    printf ("---=== IPC Temperature Analyzer ===---\n"); // Displays the title of the output and what it is going to be doing.

    for (i = 1; i <= NUMS; i++) // The initliazation (declared), the condition, and the changes within the for loop statement.
    {           // Starts the for loop body of the program.

        do // Starts the do while within the for loop of the program.
        {    // Starts the do while body of the for loop in the program. 

            printf ("Enter the high value for day %d: ", i); // Asks the user to put the high temperature values for day 1-3.
            scanf ("%d", &high); // User inputs the high temperature values.

            printf ("\n"); // Adds a new line.

            printf ("Enter the low value for day %d: ", i); // Asks the user to put the low temperature values for day 1-3.
            scanf ("%d", &low); // User inputs the low temperature values.

            printf ("\n");

            // If the user puts high temperature values as greater than 40 or low temperature values as less than -40.
            if (high > 40 || low < -40 || high < low)
            {
                printf ("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n"); // Displays that the user inputted incorrect values.
                
                printf ("\n"); // Adds a new line.
            }
             
            else // If the user doesn't put high temperature values as greater than 40 or low temperature values as less than -40.
            {
                // It adds the high and low temperature values (if correct/true) for all days with the average (method: +=) and is assigned to that variable.
                average += high + low;
            }
           

        } // Ends the do while body of the for loop in the program. 

        //It loops the same day that the user inputted the false temperature values until they put the correct values.
        while (high > 40 || low < -40 || high < low);
        
    } // Ends the for loop body of the program.

    //Out of the for loop, the average is divided by the NUMS variable, which is 3 and is then multiplied by 2 to be assigned to the average at the left side.
    average = average / (NUMS * 2);
    printf ("The average (mean) temperature was: %.2f\n", average); // Displays what the average (mean) temperature is for all three days.

    return (0); // Returns the codes back to the OS.

}  // To end the body of the program.
