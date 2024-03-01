// Kevin Robles
// Chpt5 PA

#include <stdio.h>
#include <stdlib.h>

// Define a stack structure
typedef struct {
    int *items; 
    int top; // Index of the top item in the stack
    int maxSize; // Maximum size of the stack
} Stack;

// Function to create a new stack
Stack* createStack(int maxSize) {
    Stack *stack = (Stack *)malloc(sizeof(Stack)); // Allocate memory for stack structure
    stack->items = (int *)malloc(sizeof(int) * maxSize); // Allocate memory for items array
    stack->top = -1; // Initialize top index to -1 indicating empty stack
    stack->maxSize = maxSize; // Set maximum size of the stack
    return stack; // Return the created stack
}

// Function to resize the stack
void stackResize(Stack *stack) {
    stack->maxSize *= 2; // Double the size of the stack
    stack->items = (int *)realloc(stack->items, sizeof(int) * stack->maxSize); // Reallocate memory for items array
}

// Function to push an item onto the stack
int push(Stack *stack, int item) {
    if (stack->top == stack->maxSize - 1) { // Check if stack is full
        stackResize(stack); // Resize stack if full
    }
    stack->items[++stack->top] = item; // Place item on top of the stack
    return 1; // Return success
}

// Function to pop an item from the stack
int pop(Stack *stack) {
    if (stack->top == -1) { // Check if stack is empty
        return -1; // Return -1 if empty
    }
    return stack->items[stack->top--]; // Return top item and decrease top index
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1 ? 1 : 0; // Return 1 if empty, 0 otherwise
}

// Function to get the top item of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) { // Check if stack is empty
        return -1; // Return -1 if empty
    }
    return stack->items[stack->top]; 
}

// Function to print the stack contents
void printStack(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) { // Loop from top to bottom of the stack
        printf("%d\n", stack->items[i]); // Print each item
    }
}

// Main function
int main() {
    int allocationSize, maxLength;
    printf("Enter the allocation size of the stack: "); // Prompt for allocation size
    scanf("%d", &allocationSize);
    printf("Enter the maximum length of the stack: "); // Prompt for maximum length
    scanf("%d", &maxLength);
    printf("\n"); // Print new line for formatting

    Stack *stack = createStack(allocationSize); // Create a new stack with given allocation size

    // Test scenario 
    if (push(stack, 1)) printf("Item 1 was pushed successfully\n");
    if (push(stack, 2)) printf("Item 2 was pushed successfully\n");
    printf("The top item on the stack is: %d\n", peek(stack));
    if (push(stack, 3)) printf("Item 3 was pushed successfully\n");
    printf("The length of the stack is: %d\n\n", stack->top + 1);

    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The top item on the stack is: %d\n\n", peek(stack));

    if (push(stack, 4)) printf("Item 4 was pushed successfully\n\n");
    printf("The Stack contents are the following: \n");
    printStack(stack);
    printf("\n");

    if (push(stack, 5)) printf("Item 5 was pushed successfully\n");
    printf("The item popped from the stack was %d\n", pop(stack));
    if (push(stack, 6)) printf("Item 6 was pushed successfully\n\n");
    printf("The Stack contents are the following: \n");
    printStack(stack);
    printf("\n");

    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The stack is empty: %s\n\n", isEmpty(stack) ? "true" : "false");

    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The stack is empty: %s\n", isEmpty(stack) ? "true" : "false");

    // Free allocated memory
    free(stack->items);
    free(stack);

    return 0;
}
