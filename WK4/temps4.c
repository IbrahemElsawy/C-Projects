/* Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) At Home: temps2.c

  Full Name: Ibrahem Elsawy
  Student ID: 157888199
  Student Email: ielsawy@myseneca.ca

*/




#define _CRT_SECURE_NO_WARNINGS // It displays no warnings when testing it in matrix.
#define NUMS 10 // It defines the NUMS variable as 10.
#include <stdio.h> // Provides the header file as well as input/output facilities of this program.

int main (void) // Starting the function of the program.
{               

    //The variables that are going to be declared for the program.
       int high[NUMS] = { 0 };
       int low[NUMS] = { 0 };
       int index;
       int numOfDays = 0;
       int highTemp = -100, lowTemp = +100;
       int highDay, lowDay, averageDay = 0;
       double totalTemp = 0;


//Displays this line on what the program is going to be about.
printf ("---=== IPC Temperature Calculator V2.0 ===---\n");


// If statement if the numOfDays is less than 3 or greater than 10.
if ((numOfDays < 3) || (numOfDays > 10))
{      


    //Asks the user to enter the number of days between the range show below.
    printf ("Please enter the number of days, between 3 and 10, inclusive: ");
    scanf ("%d", &numOfDays); // User inputs the number.
    printf ("\n");


    // The while loop for if the user inputted numOfDays as less than 3 or greater than 10.
    while ((numOfDays < 3) || (numOfDays > 10))
    {
        printf ("Invalid entry, please enter a number between 3 and 10, inclusive: "); // Asks the user to enter the correct number again.
        scanf ("%d", &numOfDays); // User inputs the number again.
        printf ("\n");
    }
}



    //The first for loop with the initialization, condition, and action declared.
    for (index = 1; index <= numOfDays; index++)
    {
       printf ("Day %d - High: ", index); // Asks the user to input the high temperature value for days 1-4.
       scanf ("%d", &high[index - 1]); // User inputs the high temperature values.



       printf ("Day %d - Low: ", index); // Asks the user to input the low temperature value for days 1-4.
       scanf ("%d", &low[index - 1]); // User inputs the low temperature values.
    }

      printf ("\n");
      printf ("Day  Hi  Low\n"); // Displays what the days and high/low temperature are going to be shown under.



     // The second for loop with the initialization, condition, and action declared.
     for (index = 0; index <= numOfDays - 1; index++)
     {

    printf ("%d    %d    %d\n", (index + 1), high[index], low[index]); // Displays what the high/low temperature values are and for which day.
     
     }

     printf ("\n");



     // The third for loop when the user inputs all high/low temp values for the following days.
    for (index = 0; index <= numOfDays - 1; index++)

  {

    // The if statement for if the high variable is greater than the highTemp.
    //The calculations for the highTemp and highDay.
    if (high[index] > highTemp)
    {
        highTemp = high[index];
        highDay = index + 1;
    }

    // The if statement for if the low variable is greater than the highTemp.
    //The calculations for the lowTemp and lowDay.
    if (low[index] < lowTemp)
    {
        lowTemp = low[index];
        lowDay = index + 1;
    }

  }


// Displays what the highest and lowest temperature on a certain day are.
printf ("The highest temperature was %d, on day %d\n", highTemp, highDay);
printf ("The lowest temperature was %d, on day %d\n", lowTemp, lowDay);
printf ("\n");


// The do statement for the average temperature and which day the user has inputted in the program.
 do
  {


    //Asks the user to enter a number between 1 and what they put for the numOfDays.
    printf ("Enter a number between 1 and %d to see the average temperature "
        "for the entered number of days, enter a negative number to exit: ", numOfDays);
    scanf ("%d", &averageDay); // User inputs which day they want to see the average temperature of.
    printf ("\n");


    // The while loop for if the averageDay is either greater than the numOfDays or if it is equal to 0.
    while ((averageDay > numOfDays) || (averageDay == 0))
    {
        // Asks the user to enter the correct number between 1 and what they put for the numOfDays.
        printf ("Invalid entry, please enter a number between 1 and %d, inclusive: ", numOfDays);
        scanf ("%d", &averageDay); // User inputs which day they want to see the average temperature of.
        printf ("\n");
    }



    // The if statement for if averageDay is greater than 0.
    if (averageDay > 0)
    {
        // The for loop to calculate the totalTemp of adding high and low variables with the index for each of them.
        for (index = 0; index <= averageDay - 1; index++)
        {
            totalTemp += high[index] + low[index];
        }
        double average = (totalTemp / (averageDay * 2)); // The calculation of the average.
        printf ("The average temperature up to day %d is: %.2f", averageDay, average); // Displays the averageDay as well as what the average temperature is.
        printf ("\n\n");
        totalTemp = 0; // Declares the totalTemp as equal to 0 again.
    }


     // The while loop if the averageDay is greater or equal to 0.
}    while (averageDay >= 0);


     // Displays goodbye if the user inputted a negative number (e.g. -8).
     printf ("Goodbye!\n");

    return 0; // Returns the codes back to the OS.

}  // To end the body of the program.
