#include <stdio.h>
#include <string.h>

// Constants
const float HIGH_DISCOUNT = 0.15;  // 15% discount
const float LOW_DISCOUNT = 0.10;   // 10% discount
const float HIGH_THRESHOLD = 1000.0; // Threshold for high discount
const float LOW_THRESHOLD = 500.0;   // Threshold for low discount

// Function to validate user input
int isValidInput(float *input) {
    if (scanf("%f", input) != 1 || *input < 0) {
        while (getchar() != '\n'); // Clear input buffer
        return 0; // Invalid input
    }
    return 1; // Valid input
}

// Function to calculate the discount
float calculateDiscount(float totalPurchase) {
    if (totalPurchase >= HIGH_THRESHOLD) {
        return totalPurchase * HIGH_DISCOUNT;
    } else if (totalPurchase >= LOW_THRESHOLD) {
        return totalPurchase * LOW_DISCOUNT;
    }
    return 0; // No discount if totalPurchase < 500
}

int main() {
    // Variables
    float price, quantity, totalPurchase, discount;
    char name[100];

    // Prompt the user to enter their full name
    printf("Please enter your full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove the trailing newline character

    // Loop to validate price input
    do {
        printf("Enter the price (Ksh): ");
        if (!isValidInput(&price)) {
            printf("Invalid input. Please enter a positive number.\n");
        }
    } while (price <= 0); // Repeat until valid input is entered

    // Loop to validate quantity input
    do {
        printf("Enter the quantity: ");
        if (!isValidInput(&quantity)) {
            printf("Invalid input. Please enter a positive number.\n");
        }
    } while (quantity <= 0); // Repeat until valid input is entered

    // Calculate the total purchase
    totalPurchase = price * quantity;

    // Calculate the discount
    discount = calculateDiscount(totalPurchase);

    // Display the total purchase and discount
    printf("\nHi %s, your total purchase is: Ksh %.2f\n", name, totalPurchase);
    printf("Your discount is: Ksh %.2f\n", discount);
    printf("Amount to pay after discount: Ksh %.2f\n", totalPurchase - discount);

    return 0;
}
