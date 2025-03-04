## Including Standard Library 

(#include <stdio.h>)

## The program uses functions from the standard input-output library to read input and display output.
## Defining Constants for Discount Rates and Thresholds

HIGH_DISCOUNT (15%) applies to purchases of 1000 or more.
LOW_DISCOUNT (10%) applies to purchases between 500 and 999.
No discount is applied for purchases below 500.

Function: isValidInput()

Ensures the user enters a valid positive number.
Uses scanf() to read input and checks if it is a valid number.
Returns 0 (false) for invalid input, 1 (true) for valid input.
Function: calculateDiscount()

## Determines the discount based on the total purchase amount.
Applies 15% discount for purchases of 1000 or more.
Applies 10% discount for purchases between 500 and 999.
Returns 0 discount if the purchase is less than 500.

Main Function (main())

Prompts the user to enter their name.
Prompts the user to enter the price of an item and quantity (validates input).
Calculates the total purchase amount (price * quantity).
Calls calculateDiscount() to compute the discount.

## Displays:
The total purchase amount.
The discount amount.
The final amount to pay after discount.