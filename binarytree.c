#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Build binary tree from user input
Node* buildTree() {
    int val;
    printf("Enter data (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1) return NULL;

    Node* root = createNode(val);

    printf("Enter left child of %d\n", val);
    root->left = buildTree();

    printf("Enter right child of %d\n", val);
    root->right = buildTree();

    return root;
}

// Traversals
void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;

    printf("Build the binary tree\n");
    root = buildTree();

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}
