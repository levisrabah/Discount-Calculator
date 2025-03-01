// A C program to input price, quantity of an item from the user and display payment according to the following conditions.
// If total purchase(price * quantity) is greater than Ksh.1000 then calculate discount 15% otherwise discount 10% of total Ksh.

# include <stdio.h>
// constants
const float HIGH_DISCOUNT = 0.15; // 15% discount
const float LOW_DISCOUNT = 0.10; // 10% discount
const float THRESHOLD = 1000.0; // Threshold for high discount

// funtion validating the user input
int isValidInput(float *input){
    if (scanf("%f", input) != 1){
        return 0; // Inavlid input
    }
    return 1; // Valid input
}
// Function to calculate the discount
float calculateDiscount(float totalPurchase){
    if (totalPurchase > THRESHOLD){
        return totalPurchase * HIGH_DISCOUNT;
    } else {
        return totalPurchase * LOW_DISCOUNT;
    }
}
int main(){
    // variables
    float price, quantity, totalPurchase, discount;
    // Prompt the user to enter the price
    printf("Enter the price Ksh: ");
    // Validate the user input
    if (!isValidInput(&price)){
        printf("Invalid input. Please enter a number.\n");
        return 1; // Terminate the program with an error code
    }
    // Prompt the user to enter the quantity

    printf("Please Enter the quantity: ");
    if (!isValidInput(&quantity)) {
    printf("Invalid input. Please enter a number.\n");
    return 1; // Terminate the program with an error code
}
    // Calculate the total purchase
    totalPurchase = price * quantity;
    // Calculate the discount
    discount = calculateDiscount(totalPurchase);
    // Display the discount
    printf("The discount is Ksh %.2f\n", discount);
    return 0;
}
