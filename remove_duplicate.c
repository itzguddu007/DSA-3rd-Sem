#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL)
        *head = *tail = newNode;
    else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void removeDuplicates(Node** head, Node** tail) {
    Node* current = *head;
    while (current != NULL) {
        Node* checker = current->next;
        while (checker != NULL) {
            if (checker->data == current->data) {
                Node* duplicate = checker;
                checker = checker->next;

                if (duplicate->prev)
                    duplicate->prev->next = duplicate->next;
                if (duplicate->next)
                    duplicate->next->prev = duplicate->prev;
                else
                    *tail = duplicate->prev;

                free(duplicate);
            } else {
                checker = checker->next;
            }
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice, val;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Display list\n");
        printf("3. Remove duplicates\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertEnd(&head, &tail, val);
                break;
            case 2:
                printf("Current List: ");
                display(head);
                break;
            case 3:
                removeDuplicates(&head, &tail);
                printf("Duplicates removed.\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}