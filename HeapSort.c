#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain max heap property
void heapify(int *arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

// Build a max heap from input data
void buildHeap(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
}

// Heap sort function
void heapSort(int *arr, int size) {
    buildHeap(arr, size);

    for (int i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Delete root (max element in max heap)
int deleteRoot(int *arr, int *size) {
    if (*size <= 0) return -1;

    int root = arr[0];
    arr[0] = arr[*size - 1];
    (*size)--;
    heapify(arr, *size, 0);
    return root;
}

// Display heap
void display(int *arr, int size) {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i, choice, deletedValue;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *heap = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    buildHeap(heap, n);

    do {
        printf("\nMenu:\n");
        printf("1. Display Heap\n");
        printf("2. Delete Max Element\n");
        printf("3. Heap Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(heap, n);
                break;

            case 2:
                deletedValue = deleteRoot(heap, &n);
                if (deletedValue != -1)
                    printf("Deleted Max Element: %d\n", deletedValue);
                else
                    printf("Heap is empty, cannot delete!\n");
                break;

            case 3:
                heapSort(heap, n);
                printf("Sorted array: ");
                for (i = 0; i < n; i++)
                    printf("%d ", heap[i]);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    free(heap);
    return 0;
}
