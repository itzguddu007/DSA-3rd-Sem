#include <stdio.h>
#include <stdlib.h>

/* Self-balancing: The tree automatically adjusts its structure to maintain balance.  
Binary search tree: It follows the rules of a BST, where left child nodes are less than the parent, 
and right child nodes are greater.  
Balance factor: The difference between the height of the left and right subtrees for 
every node is always \(-1\), \(0\), or \(1\).  
fficient operations: Due to its balanced nature, operations like searching, inserting, and 
deleting are performed in \(O(log\ n)\) time. */


typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

int height(Node *n) {
    if (n)
        return n->height;
    else
        return 0;
}


int getBalance(Node* n) {
    if (n)
        return height(n->left) - height(n->right);
    else
        return 0;
}


int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotate
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left rotate
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}


// Insertion
Node* insert(Node* root, int key) {
    if (!root) return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // duplicate not allowed

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);


    // Balancing cases
    //LEFT LEFT
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    //RIGHT RIGHT
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    //LEFT RIGHT
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    //RIGHT LEFT 
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Find node with minimum key
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

// Deletion
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp;
            if (root->left)
                temp = root->left;
            else
                temp = root->right;
            if (!temp) {
                free(root);
                return NULL;
            } else {
                *root = *temp;
                free(temp);
            }
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Balance the node
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

// Menu-driven main
int main() {
    Node* root = NULL;
    int choice, val;

    do {
        printf("\n--- AVL Tree Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
        }
    } while (choice != 0);

    return 0;
}