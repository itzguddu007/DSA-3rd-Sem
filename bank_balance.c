#include <stdio.h>

float balance = 0.0;

void credit(float amount) {
    balance += amount;
    printf("Credited: %.2f\n", amount);
}

void debit(float amount) {
    if (amount > balance)
        printf("Insufficient balance!\n");
    else {
        balance -= amount;
        printf("Debited: %.2f\n", amount);
    }
}

void checkBalance() {
    printf("Current balance: %.2f\n", balance);
}

void displayStatement() {
    printf("=== Account Statement ===\n");
    printf("Total Balance: %.2f\n", balance);
    printf("=========================\n");
}

int main() {
    int choice;
    float amount;

    do {
        printf("\n---- Menu ----\n");
        printf("1. Credit\n");
        printf("2. Debit\n");
        printf("3. Check Balance\n");
        printf("4. Display Statement\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to credit: ");
                scanf("%f", &amount);
                credit(amount);
                break;
            case 2:
                printf("Enter amount to debit: ");
                scanf("%f", &amount);
                debit(amount);
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                displayStatement();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } 
    while (choice != 5);

    return 0;
}
