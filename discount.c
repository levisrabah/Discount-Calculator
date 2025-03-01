#include <stdio.h>

// Constants
const float HIGH_DISCOUNT = 0.15; // 15% discount
const float LOW_DISCOUNT = 0.10;  // 10% discount
const float THRESHOLD = 1000.0;   // Threshold for high discount

// Function validating the user input
int isValidInput(float *input) {
    if (scanf("%f", input) != 1) {
        return 0; // Invalid input
    }
    return 1; // Valid input
}

// Function to calculate the discount
float calculateDiscount(float totalPurchase) {
    if (totalPurchase > THRESHOLD) {
        return totalPurchase * HIGH_DISCOUNT;
    } else {
        return totalPurchase * LOW_DISCOUNT;
    }
}

int main() {
    // Variables
    float price, quantity, totalPurchase, discount;
    char name[50];

    // Prompt the user to enter their name
    printf("Please Enter your name: ");
    scanf("%s", name);

    // Prompt the user to enter the price
    printf("Enter the price Ksh: ");
    // Validate the user input
    if (!isValidInput(&price)) {
        printf("Invalid input. Please enter a number.\n");
        return 1; // Terminate the program with an error code
    }

    // Prompt the user to enter the quantity
    printf("Please enter the quantity: ");
    if (!isValidInput(&quantity)) {
        printf("Invalid input. Please enter a number.\n");
        return 1; // Terminate the program with an error code
    }

    // Calculate the total purchase
    totalPurchase = price * quantity;

    // Calculate the discount
    discount = calculateDiscount(totalPurchase);

    // Display the personalized discount message
    printf("Hi %s, your discount is: Ksh %.2f\n", name, discount);

    return 0;
}