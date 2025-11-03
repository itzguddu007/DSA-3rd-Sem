#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // circular link
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

// Display list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n"); 
        return;
    }
    Node* temp = head;
    printf("Circular List: ");
    while (temp->next != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> (head)\n", temp->data);
}


// Find middle node
void findMiddle(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle node: %d\n", slow->data);
}

int main() {
    Node* head = NULL;
    int choice, val;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Display list\n");
        printf("3. Find middle node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 2:
                display(head);
                break;
            case 3:
                findMiddle(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}