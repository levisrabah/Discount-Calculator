#include <stdio.h>

// Constants
const float HIGH_DISCOUNT = 0.15; // 15% discount
const float LOW_DISCOUNT = 0.10;  // 10% discount
const float HIGH_THRESHOLD = 1000.0; // Threshold for high discount
const float LOW_THRESHOLD = 500.0;   // Threshold for low discount

// Function to validate the user input
int isValidInput(float *input) {
    if (scanf("%f", input) != 1 || *input < 0) {
        return 0; // Invalid input
    }
    return 1; // Valid input
}

// Function to calculate the discount
float calculateDiscount(float totalPurchase) {
    if (totalPurchase >= HIGH_THRESHOLD) {
        return totalPurchase * HIGH_DISCOUNT;
    } else if (totalPurchase >= LOW_THRESHOLD) {  // Corrected condition
        return totalPurchase * LOW_DISCOUNT;
    }
    return 0; // No discount if totalPurchase < 500
}

int main() {
    // Variables
    float price, quantity, totalPurchase, discount;
    char name[50];

    // Prompt the user to enter their name
    printf("Please enter your name: ");
    scanf("%s", name);

    // Prompt the user to enter the price
    printf("Enter the price (Ksh): ");
    if (!isValidInput(&price)) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1; // Terminate the program with an error code
    }

    // Prompt the user to enter the quantity
    printf("Enter the quantity: ");
    if (!isValidInput(&quantity)) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1; // Terminate the program with an error code
    }

    // Calculate the total purchase
    totalPurchase = price * quantity;

    // Calculate the discount
    discount = calculateDiscount(totalPurchase);

    // Display the total purchase and discount
    printf("Hi %s, your total purchase is: Ksh %.2f\n", name, totalPurchase);
    printf("Your discount is: Ksh %.2f\n", discount);
    printf("Amount to pay after discount: Ksh %.2f\n", totalPurchase - discount);

    return 0;
}

