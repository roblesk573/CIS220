// Kevin Robles
// Chpt4 PA

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void appendNode(Node** head, int data);
void prependNode(Node** head, int data);
void insertAfterNode(Node* prevNode, int data);
void removeNode(Node** head, int key);
void displayList(Node* node);
Node* searchNode(Node* head, int key);
int sumDataValues(Node* head);

// Main function
int main() {
    Node* head = NULL;

    // Append nodes with data 1 and 2
    appendNode(&head, 1);
    appendNode(&head, 2);
   
    // Prepend a node with data 3
    prependNode(&head, 3);
   
    // Insert nodes with data 4, 5, 6, and 7 at specified positions
    insertAfterNode(head, 4); // After head
    appendNode(&head, 5); // At the end
    Node* node4 = searchNode(head, 4);
    if (node4 != NULL) insertAfterNode(node4, 6);
    Node* node2 = searchNode(head, 2);
    if (node2 != NULL) insertAfterNode(node2, 7);

    // Display list
    printf("The list order is: ");
    displayList(head);

    // Remove nodes as specified
    removeNode(&head, head->data); // Remove head node
    Node* node7 = searchNode(head, 7);
    if (node7 != NULL && node7->next != NULL) {
        removeNode(&head, node7->next->data); // Remove node after node with data 7
    }

    // Display list again
    printf("The list order is: ");
    displayList(head);

    // Search for nodes with data 5 and 2, display results
    Node* foundNode5 = searchNode(head, 5);
    printf("Node with data 5 was %sfound.\n", foundNode5 ? "" : "not ");
    Node* foundNode2 = searchNode(head, 2);
    printf("Node with data 2 was %sfound.\n", foundNode2 ? "" : "not ");

    // Sum and display the sum of the node values
    int sum = sumDataValues(head);
    printf("The sum of the Linked List data values is %d\n", sum);

    // Free allocated memory (not shown for brevity)

    // Clean up before exiting
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Implementations of functions
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void prependNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAfterNode(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void removeNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void displayList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int sumDataValues(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}
