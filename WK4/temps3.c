/* Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) At Home: temps2.c

  Full Name: Ibrahem Elsawy
  Student ID: 157888199
  Student Email: ielsawy@myseneca.ca

*/

#define _CRT_SECURE_NO_WARNINGS // It displays no warnings when testing it in matrix.
#define NUMS 10 // It defines the NUMS variable as 10.
#include <stdio.h> // Provides the header file as well as input/output facilities of this program.

int main (void) // Starting the function of the program.
{                      // Starts the for loop body of the program.

    int highTotal = 0, lowTotal = 0, days = 0, averageDay = 0, totalTemp = 0, highTemp = -40, lowTemp = 40, highDay, lowDay, i, numOfDays = 5; // The int variables that are going to be declared for this program.
    int high[NUMS]; // The array definition of the high variable.
    int low[NUMS]; // The array definition of the low variable.
    float average = 0;

    printf ("---=== IPC Temperature Calculator V2.0 ===---\n"); // Prints what the name of the output program.

    printf ("Please enter the number of days, between 3 and 10, inclusive: "); //Tells the user to enter the number of days between the ranges 3-10.
    scanf ("%d", &numOfDays); // User inputs the number of days.

        // The while loop for if the user has inputted values that are out of range.
    while ((numOfDays < 3) || (numOfDays > 10))
    {                   //Starts first the while loop body of the program.
        printf ("\nInvalid entry, please enter a number between 3 and 10, inclusive: "); // Tells the user to enter the correct number of days between the ranges 3-10.
        scanf ("%d", &numOfDays); // User inputs the number of days again.
    }                   // Ends the first while loop body of the program.

    printf ("\n"); // Displays a new line.


    for (i = 1; i <= numOfDays; i++) // The initliazation (declared), the condition, and the changes within the for loop statement.
    {           // Starts the first for loop body of the program.

        printf ("Day %d - High: ", i); // Asks the user to put the high temperature values for day 1-4.
        scanf ("%d", &high[i - 1]); // User inputs the high temperature values, (the high element's index is being subtracted by 1 to get the correct output of high temp values).

        printf ("Day %d - Low: ", i); // Asks the user to put the low temperature values for day 1-4.
        scanf ("%d", &low[i - 1]); // User inputs the low temperature values (the low element's index is being subtracted by 1 to get the correct output of low temp values).
    }           // Ends the first for loop body of the program.




    printf ("\nDay  Hi  Low"); // Prints the message of day, and high and low temperature values.

    for (i = 1; i <= numOfDays; i++) // The initliazation (declared), the condition, and the changes within the for loop statement.
    { // Starts the seconds for loop body of the program.

        printf ("\n%d", i); // Displays what the days are.

        printf ("    %d", high[i - 1]); // Displays the high temperature values (the high element's index is being subtracted by 1 to get the correct output of high temp values).

        printf ("    %d", low[i - 1]); // Displays the low temperature values (the low element's index is being subtracted by 1 to get the correct output of low temp values).

        if (highTemp < high[i - 1]) // The condition for the if statement of highTemp with the high element's index being subtracted by 1.
        {         // Starts the first if statement body of the program.
            
            highTemp = high[i - 1]; // The calculation of the highTemp with the high element's index being subtracted by 1.
            highDay = i;            // The calculation of the highDay with the i variable being assigned to it.
           
        }         // Ends the first if statement body of the program.

        if (lowTemp > low[i - 1]) // The condition for the if statement of lowTemp with the low element's index being subtracted by 1.
        {         // Starts the second if statement body of the program.
            
            lowTemp = low[i - 1];   // The calculation of the lowTemp with the low element's index being subtracted by 1.
            lowDay = i;             // The calculation of the lowDay with the i variable being assigned to it.

        }          // Ends the second if statement body of the program.

    } // Ends the second for loop body of the program.

  
    
       printf ("\n"); // Prints a new line.
   
       printf ("\nThe highest temperature was %d, on day %d\n", highTemp, highDay); // Displays what the high temperature is on which day.

       printf ("\nThe lowest temperature was %d, on day %d\n", lowTemp, lowDay); // Displays what the low temperature is on which day.
    
       
       printf ("\n"); // Displays a new line.

       printf ("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numOfDays); // Prints what the user should input.
       scanf ("%d", &averageDay); // Asks the user to input the number between the 1 and the numOfDays they putted at the beginning of the output program or if they want to exit.

       // The while loop for if the user wants to either check for the average of the day or if they want to exit the output program.
       while (averageDay >= 0) 
       {                   // Starts the second while loop body of the program.

               // The while loop for if the user has inputted a number that is greater than what they putted for the numOfDays at the beginning (e.g. 6 or 7).
               while (averageDay > numOfDays || averageDay == 0)
               {          // Starts the third while loop body of the program.
                   printf ("\n"); // Prints a new line.
                   printf ("Invalid entry, please enter a number between 1 and 5, inclusive: "); // Prints how it is an invalid entry.
                   scanf ("%d", &averageDay); // User inputs the correct (or wrong) number.
                   
               }          // Ends the third while loop body of the program.

               if (averageDay > 0)
               { 
               // If the user has inputted a number that is less than what they putted for the numOfDays at the beginning (e.g. 3 or 4).
               for (i = 1; i <= averageDay; i++)
               {         // Starts the third for loop body of the program.

                  totalTemp = high[i - 1] + low[i - 1]; // The calculation for the highTotal with the high's element index being subtracted by 1.
                   ; // The calculation for the lowTotal with the low's element index being subtracted by 1.

               }         // Ends the third for loop body of the program.
                
               }
               // The calculation for the average temperature of a certain day.
               double average = (totalTemp / numOfDays * 2);
               printf ("\n"); // Prints a new line.
               printf ("The average temperature up to day %d is: %.2f", averageDay, average); // Displays what the average temperature and which day it is on.
               totalTemp = 0; // Puts the highTotal's identifier back to 0.
               average = 0; // Puts the average's identifier back to 0.
           
           
           printf ("\n"); // Prints a new line.

           // Prints what the user should input again.
           printf ("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numOfDays);
           scanf ("%d", &averageDay); // Asks the user to input the number between the 1 and the numOfDays they putted at the beginning of the output program or if they want to exit again.
       }  // Ends the second while loop body of the program.
         
         printf ("\n"); // Prints a new line.
        
         printf ("Goodbye!\n"); // Displays goodbye to the user while exiting the output program.
         
            
            
       return (0); // Returns the codes back to the OS.

}          // To end the body of the program.
 
