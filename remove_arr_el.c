#include <stdio.h>
#include <stdlib.h>

void searchElement(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d\n", key, i);
            return;
        }
    }
    printf("Element %d not found.\n", key);
}

int removeDuplicates(int *arr, int n) {
    int i, j = 0;

    for (i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int k = 0; k < j; k++) {
            if (arr[i] == arr[k]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate==0) {
            arr[j++] = arr[i];  // Keep unique elements
        }
    }

    return j;  // new size
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int key;
    printf("Enter the value of key");
    scanf("%d",&key);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    searchElement(arr,n,key);
    n = removeDuplicates(arr, n);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
