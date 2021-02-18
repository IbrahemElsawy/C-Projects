/* Ibrahem's Introduction to Programming Using C (IPC144 - NQQ) At Lab: Cash Register
  
  Full Name: Ibrahem Elsawy
  Student ID: 157888199
  Student Email: ielsawy@myseneca.ca

*/


#include <stdio.h> // It provides the header file as well as input/output facilities of the C Program.

int main (void)    // The main () is to start the function of the program.

{                  // This is to start the body of the program.
      
      double balanceOwing, cash; // The double float variable for this program.
      int loonies, quarters; // The integer variables for this program.
     
      printf ("Please enter the amount to be paid: $"); // This is to ask the user to enter the amount of money that needs to be paid.
      s_scanf("%lf", &cash); // This program stores the data that the user has put.


      loonies = (int)(100*cash/100);   // This converts the cash variable on the right side into an integer for the integer variable, "loonies" on the left side.
      printf ("Loonies required: %d, ", loonies); // This tells the user how many loonies are required to pay the amount.

      balanceOwing = cash - loonies; // It does the calculation of subtracting the amount of cash by the number of loonies 
                                     //This is in order to get the balance that needs to be owed.

      printf ("balance owing is: $%.2f\n", balanceOwing); // It displays how much balance the user needs to owe without loonies.

      quarters = (int)(100*balanceOwing/25);  // It converts the remaining float variable, "balanceOwing" on the right side into an integer variable.
                                              // It then gets multiplied by 100 at first and divided by 25 next in order to get the correct amount of quarters. 
     
      printf ("Quarters required are: %d, ", quarters); // This tells the user how many quarters are required to pay the remaining amount.
      
      balanceOwing = balanceOwing - (quarters*.25);  // It does the calculation of subtracting the amount of the owed balance by the amount of quarters multiplied by .25.
      printf ("balance owing is: $%.2f\n", balanceOwing); // It display how much balance the user needs to owe without loonies AND quarters.


      return (0); // This is to return the codes back to the operating system (OS).
 
} // This is used to end the body of the program.
