#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int top;
    int maxSize;
} Stack;

Stack* createStack(int maxSize) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->items = (int *)malloc(sizeof(int) * maxSize);
    stack->top = -1;
    stack->maxSize = maxSize;
    return stack;
}

void stackResize(Stack *stack) {
    stack->maxSize *= 2;
    stack->items = (int *)realloc(stack->items, sizeof(int) * stack->maxSize);
}

int push(Stack *stack, int item) {
    if (stack->top == stack->maxSize - 1) {
        stackResize(stack); // Automatically resize if trying to push to a full stack
    }
    stack->items[++stack->top] = item;
    return 1; // In this context, push is always successful due to resizing
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        return -1; // Return -1 if the stack is empty
    }
    return stack->items[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1 ? 1 : 0;
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        return -1; // Return -1 if the stack is empty
    }
    return stack->items[stack->top];
}

void printStack(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}

int main() {
    int allocationSize, maxLength, item;
    printf("Enter the allocation size of the stack: ");
    scanf("%d", &allocationSize);
    printf("Enter the maximum length of the stack: ");
    scanf("%d", &maxLength);

    Stack *stack = createStack(allocationSize);

    // Following the test scenario
    if (push(stack, 1)) printf("Item 1 was pushed successfully\n");
    if (push(stack, 2)) printf("Item 2 was pushed successfully\n");
    printf("The top item on the stack is: %d\n", peek(stack));
    if (push(stack, 3)) printf("Item 3 was pushed successfully\n");
    printf("The length of the stack is: %d\n", stack->top + 1);

    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The top item on the stack is: %d\n", peek(stack));

    if (push(stack, 4)) printf("Item 4 was pushed successfully\n");
    printf("The Stack contents are the following: \n");
    printStack(stack);

    if (push(stack, 5)) printf("Item 5 was pushed successfully\n");
    printf("The item popped from the stack was %d\n", pop(stack));
    if (push(stack, 6)) printf("Item 6 was pushed successfully\n");
    printf("The Stack contents are the following: \n");
    printStack(stack);

    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The stack is empty: %s\n", isEmpty(stack) ? "true" : "false");

    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The item popped from the stack was %d\n", pop(stack));
    printf("The stack is empty: %s\n", isEmpty(stack) ? "true" : "false");

    // Clean up
    free(stack->items);
    free(stack);

    return 0;
}
