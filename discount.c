#include <stdio.h>
#include <string.h>  // Required for strcmp() and strcspn()

// Constants
const float HIGH_DISCOUNT = 0.15; // 15% discount
const float LOW_DISCOUNT = 0.10;  // 10% discount
const float HIGH_THRESHOLD = 1000.0; // Threshold for high discount
const float LOW_THRESHOLD = 500.0;   // Threshold for low discount

// Function to validate the user input
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
    char name[50], choice;

    while (1) {
        // Prompt the user to enter their name
        printf("\nPlease enter your name : ");
        fgets(name, sizeof(name), stdin);

        // Remove newline character from the name input
        name[strcspn(name, "\n")] = 0;

        // Check if the user wants to quit
        if (strcmp(name, "q") == 0 || strcmp(name, "Q") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        // Prompt the user to enter the price
        printf("Enter the price (Ksh): ");
        if (!isValidInput(&price)) {
            printf("Invalid input. Please enter a positive number.\n");
            continue; // Restart loop
        }

        // Prompt the user to enter the quantity
        printf("Enter the quantity: ");
        if (!isValidInput(&quantity)) {
            printf("Invalid input. Please enter a positive number.\n");
            continue; // Restart loop
        }

        // Calculate the total purchase
        totalPurchase = price * quantity;

        // Calculate the discount
        discount = calculateDiscount(totalPurchase);

        // Display the total purchase and discount
        printf("\nHi %s, your total purchase is: Ksh %.2f\n", name, totalPurchase);
        printf("Your discount is: Ksh %.2f\n", discount);
        printf("Amount to pay after discount: Ksh %.2f\n", totalPurchase - discount);

        // Ask user if they want to continue or quit
        printf("\nPress 'q' to quit or any other key to continue: ");
        while (getchar() != '\n'); // Clear input buffer
        scanf("%c", &choice);
        while (getchar() != '\n'); // Clear buffer after choice input

        if (choice == 'q' || choice == 'Q') {
            printf("Exiting program. Welcome Again!\n");
            break;
        }
    }

    return 0;
}
