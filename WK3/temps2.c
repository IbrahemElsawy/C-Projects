/* Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) At Home: Temperature

  Full Name: Ibrahem Elsawy
  Student ID: 157888199
  Student Email: ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // It displays no warnings when testing it in matrix.
#define NUMS 4 // It defines the NUMS variable as 4.
#include <stdio.h> // Provides the header file as well as input/output facilities of this program.

int main (void) // Starting the function of the program.

{                   // To start the body of the program.

    // The int and float variables that will be declared for this program.
    int lowTemp = 40, lowDay = 0, highTemp = -40, highDay = 0, i, high = 0, low = 0;
    float average = 0, highAverage = 0, lowAverage = 0;

    printf ("---=== IPC Temperature Analyzer ===---\n"); // Displays the title of the output and what it is going to be doing.

    for (i = 1; i <= NUMS; i++) // The initliazation (declared), the condition, and the changes within the for loop statement.
    {           // Starts the for loop body of the program.

        do // Starts the do while within the for loop of the program.
        {    // Starts the do while body of the for loop in the program. 

            printf ("Enter the high value for day %d: ", i); // Asks the user to put the high temperature values for day 1-3.
            scanf ("%d", &high); // User inputs the high temperature values.

            printf ("\n"); // Displays a new line.

            printf ("Enter the low value for day %d: ", i); // Asks the user to put the low temperature values for day 1-3.
            scanf ("%d", &low); // User inputs the low temperature values.

            printf ("\n"); // Displays a new line.

            // If the user puts high temperature values as greater than 40 or low temperature values as less than -40.
            if (high > 40 || low < -40 || high <= low)
            {
                printf ("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n"); // Displays that the user inputted incorrect values.

                printf ("\n"); // Displays a new line.

            }

            else // If the user doesn't put high temperature values as greater than 40 or low temperature values as less than -40.
            {
                // It adds the high and low temperature values (if correct/true) for all days with the average (method: +=) and is assigned to that variable.
                // It also adds the high temperature values with the highAverage (method: +=) and is assigned to that variable. Same for low temperature with the lowAverage.

                average += high + low;
                highAverage += high;
                lowAverage += low;

                // If the highTemp is less than high (which is equal to -40), it will assign the high to the highTemp variable.
                // It also assigns the i (variable for days) to highDay variable.
                if (highTemp < high)
                {                    // Starts the if body of the program for the highTemp and highDay.

                highTemp = high;
                highDay = i;
                
                }                   // Ends the if body of the program for the highTemp and highDay.

                // If the highTemp is less than high (which is equal to -40), it will assign the high to the highTemp variable.
                // It also assigns the i (variable for days) to highDay variable.
                if (lowTemp > low)
                {                  // Starts the if body of the program for the lowTemp and lowDay.
                   
                   lowTemp = low;
                   lowDay = i;

                }                  // Ends the if body of the program for the lowTemp and lowDay.

                
            } // Ends the do while body of the for loop of the program.


        } // Ends else (that has if statements) body of the program.

        //It loops the same day that the user inputted the false temperature values until they put the correct values.
        while (high > 40 || low < -40 || high < low);

    } // Ends the for loop body of the program.

    //Out of the for loop, the average is divided by the NUMS variable, which is 4 to be assigned to the lowAverage and highAverage at the left side.
    
    // As for the average, it is the same as the lowAverage and highAverage except it is then multiplied by 2 to be assigned to the average at the left side.
    
    lowAverage = lowAverage / NUMS;
    printf ("The average (mean) LOW temperature was: %.2f\n", lowAverage); // Displays the average (mean) LOW temperature.
    
    highAverage = highAverage / NUMS;
    printf ("The average (mean) HIGH temperature was: %.2f\n", highAverage); // Displays the average (mean) HIGH temperature.

    average = average / (NUMS * 2);
    printf ("The average (mean) temperature was: %.2f\n", average); // Displays what the average (mean) temperature is for all three days.
     

    printf ("The highest temperature was %d, on day %d\n", highTemp, highDay); // Displays what the highest temperature is and which day it occured.


    printf ("The lowest temperature was %d, on day %d\n", lowTemp, lowDay); // Displays what the lowest temperature is and which day it occured.

      
    return (0); // Returns the codes back to the OS.

}  // To end the body of the program.
