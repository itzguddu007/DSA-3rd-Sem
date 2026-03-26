 #include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create node
Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Insert into BST
Node* insert(Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Difference calculation
int getDifference(Node* root) {
    if (!root) return 0;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int level = 1, oddSum = 0, evenSum = 0;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Node* temp = queue[front++];

            if (level % 2)
                oddSum += temp->data;
            else
                evenSum += temp->data;

            if (temp->left) queue[rear++] = temp->left;
            if (temp->right) queue[rear++] = temp->right;
        }
        level++;
    }

    return oddSum - evenSum;
}

int main() {
    Node* root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Difference = %d", getDifference(root));
}