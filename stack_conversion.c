#include<stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

// Define the Stack structure
struct Stack {
    int top;
    int maxSize;
    char* array;   // Change from int* to char* to store characters
};

// Function to create a stack
struct Stack* create(int max) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxSize = max;
    stack->top = -1;
    stack->array = (char*)malloc(stack->maxSize * sizeof(char)); // Allocate memory for char type
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    if (stack->top == stack->maxSize - 1) {
        // printf("Will not be able to push, maxSize reached\n"); // Removed for cleaner output
    }
    return stack->top == stack->maxSize - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';  // Return '\0' if stack is empty
    return stack->array[stack->top--];
}

// Function to peek the top item of the stack
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';  // Return '\0' if stack is empty
    return stack->array[stack->top];
}

// Function to check if a character is an operand
int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'); // Added numbers as operands
}

// Function to return the precedence of operators
int precedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

// Function to convert infix to postfix expression
int convertInfixToPostfix(char* expression) {
    int i = 0;
    char postfix[200] = ""; // Output postfix expression
    int pos = 0;

    struct Stack* stack = create(strlen(expression));
    if (!stack) return -1;

    while (expression[i]) {
        // If current character is a digit, collect the full number
        if (isdigit(expression[i])) {
            while (isdigit(expression[i])) {
                postfix[pos++] = expression[i++];
            }
            postfix[pos++] = ' '; // Add space after number
            i--; // Adjust index because of outer loop increment
        }
        else if (isalpha(expression[i])) {
            postfix[pos++] = expression[i];
            postfix[pos++] = ' ';
        }
        else if (expression[i] == '(') {
            push(stack, expression[i]);
        }
        else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[pos++] = pop(stack), postfix[pos++] = ' ';
            if (!isEmpty(stack) && peek(stack) == '(')
                pop(stack);
            else
                return -1;
        }
        else if (strchr("+-*/^", expression[i])) {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)) && expression[i] != '^')
                postfix[pos++] = pop(stack), postfix[pos++] = ' ';
            push(stack, expression[i]);
        }
        i++;
    }

    while (!isEmpty(stack)) {
        postfix[pos++] = pop(stack);
        postfix[pos++] = ' ';
    }

    postfix[pos - 1] = '\0'; // Remove last space and terminate string
    printf("Postfix Expression: %s\n", postfix);

    free(stack->array);
    free(stack);
    return 0;
}

// Main function to test the conversion
int main() {
    char expression[100]; // Declare a character array to store user input

    printf("Enter an infix expression (max 99 characters): ");
    fgets(expression, sizeof(expression), stdin); // Read user input

    // Remove the trailing newline character if it exists
    expression[strcspn(expression, "\n")] = 0;

    convertInfixToPostfix(expression); // Pass the user-provided expression

    return 0;
}
