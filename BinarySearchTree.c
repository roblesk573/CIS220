// Kevin Robles
// Chpt7 PA

#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Binary Search Tree structure
typedef struct BST {
    Node *root;
} BST;

// Function prototypes
Node *createNode(int key);
Node *BSTRemove(BST *tree, int key);
void print2DUtil(Node *root, int space);
void print2D(Node *root);
void insert(BST *tree, int key);

// Create a new node
Node *createNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Remove a node from the binary search tree
Node *BSTRemove(BST *tree, int key) {
    Node *par = NULL;
    Node *cur = tree->root;
    while (cur != NULL) {
        if (cur->key == key) {
            if (cur->left == NULL && cur->right == NULL) {
                if (par == NULL)
                    tree->root = NULL;
                else if (par->left == cur)
                    par->left = NULL;
                else
                    par->right = NULL;
                free(cur);
                printf("Leaf node %d was removed.\n", key);
            } else if (cur->right == NULL) {
                if (par == NULL)
                    tree->root = cur->left;
                else if (par->left == cur)
                    par->left = cur->left;
                else
                    par->right = cur->left;
                free(cur);
                printf("Node %d with only left child was removed.\n", key);
            } else if (cur->left == NULL) {
                if (par == NULL)
                    tree->root = cur->right;
                else if (par->left == cur)
                    par->left = cur->right;
                else
                    par->right = cur->right;
                free(cur);
                printf("Node %d with only right child was removed.\n", key);
            } else {
                Node *suc = cur->right;
                Node *sucPar = cur;
                while (suc->left != NULL) {
                    sucPar = suc;
                    suc = suc->left;
                }
                int successorData = suc->key;
                if (sucPar->left == suc) {
                    sucPar->left = suc->right;
                } else {
                    sucPar->right = suc->right;
                }
                free(suc);
                cur->key = successorData;
                printf("Node %d with a right and left child was removed.\n", key);
            }
            return NULL;
        } else if (cur->key < key) {
            par = cur;
            cur = cur->right;
        } else {
            par = cur;
            cur = cur->left;
        }
    }
    printf("Node %d was not removed.\n", key);
    return NULL;
}

// Print the binary search tree
void print2DUtil(Node *root, int space) {
    if (root == NULL)
        return;
    space += 10;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    print2DUtil(root->left, space);
}

void print2D(Node *root) {
    print2DUtil(root, 0);
}

// Insert a node into the binary search tree
void insert(BST *tree, int key) {
    Node *newNode = createNode(key);
    int rootInserted = 0;
    printf("Inserting node %d\n", key);
    if (tree->root == NULL) {
        printf("Inserted node %d as the root node.\n", key);
        tree->root = newNode;
        rootInserted = 1;
    } else {
        Node *temp = tree->root;
        Node *parent = NULL;
        while (temp != NULL) {
            parent = temp;
            if (key < temp->key) {
                printf("Checking node %d for left child.\n", temp->key);
                temp = temp->left;
                if (temp != NULL) {
                    printf("Traversed to left child node %d.\n", temp->key);
                }
            } else {
                printf("Checking node %d for right child.\n", temp->key);
                temp = temp->right;
                if (temp != NULL)
                    printf("Traversed to right child node %d.\n", temp->key);
            }
        }
        if (!rootInserted) {
            if (key < parent->key) {
                printf("Inserting node %d as left child of node %d.\n", key, parent->key);
                parent->left = newNode;
            } else {
                printf("Inserting node %d as right child of node %d.\n", key, parent->key);
                parent->right = newNode;
            }
        }
    }
    printf("\n");
}

// BST Demo
int main() {
    BST tree = {NULL};
    
    // Insert nodes
    insert(&tree, 20);
    insert(&tree, 35);
    insert(&tree, 13);
    insert(&tree, 6);
    insert(&tree, 24);
    insert(&tree, 18);
    insert(&tree, 48);
    insert(&tree, 1);
    insert(&tree, 27);

    // Print the initial tree
    printf("\n-----------------------------------------------------------------------\n");
    printf("Initial Binary Search Tree:\n");
    print2D(tree.root);
    
    // Remove nodes 18 and 48
    BSTRemove(&tree, 18);
    BSTRemove(&tree, 48);
    printf("\n-----------------------------------------------------------------------\n");
    printf("Binary Search Tree after removing nodes 18 and 48:\n");
    print2D(tree.root);
    
    // Insert nodes 16 and 45
    insert(&tree, 16);
    insert(&tree, 45);
    printf("\n-----------------------------------------------------------------------\n");
    printf("Binary Search Tree after inserting nodes 16 and 45:\n");
    print2D(tree.root);
    
    // Remove nodes 6 and 24
    BSTRemove(&tree, 6);
    BSTRemove(&tree, 24);
    printf("\n-----------------------------------------------------------------------\n");
    printf("Binary Search Tree after removing nodes 6 and 24:\n");
    print2D(tree.root);
    
    // Remove node 20 and attempt to remove node 38 (not in tree)
    BSTRemove(&tree, 20);
    BSTRemove(&tree, 38); // Attempt to remove a node not in the tree
    printf("\n-----------------------------------------------------------------------\n");
    printf("Binary Search Tree after removing nodes 20 and 38:\n");
    print2D(tree.root);

    return 0;
}
