#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    stack->array[++stack->top] = value;
}

int pop(Stack* stack) {
    return stack->array[stack->top--];
}

int evaluatePostfix(const char* expr) {
    Stack* stack = createStack(strlen(expr));
    for (int i = 0; expr[i]; i++) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            push(stack, num);
            i--; // Adjust position
        }
        else {
            int val2 = pop(stack);
            int val1 = pop(stack);
            switch (expr[i]) {
                case '+': push(stack, val1 + val2); break;
                case '-': push(stack, val1 - val2); break;
                case '*': push(stack, val1 * val2); break;
                case '/': push(stack, val1 / val2); break;
            }
        }
    }
    int result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char expr[100];
    printf("Enter postfix expression (use spaces between tokens): ");
    fgets(expr, sizeof(expr), stdin);
    printf("Result = %d\n", evaluatePostfix(expr));
    return 0;
}