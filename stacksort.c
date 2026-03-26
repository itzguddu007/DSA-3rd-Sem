#include <stdio.h>

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int stack[100];
    int top = -1;

    // input
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    // Bubble sort logic on stack array
    for (int i = 0; i <= top; i++) {
        for (int j = 0; j < top - i; j++) {
            if (stack[j] > stack[j + 1]) {
                int temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }

    // print sorted
    printf("Sorted:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}