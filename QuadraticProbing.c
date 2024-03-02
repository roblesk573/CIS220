// Kevin Robles
// Chpt 6 PA

#include <stdio.h>
#include <stdbool.h>

// Defining the size of the hash table  
#define TABLE_SIZE 16

// Defining special values to represent empty states in the hash table
#define EMPTY_SINCE_START -1  
#define EMPTY_AFTER_REMOVAL -2

// Defining constants for quadratic probing
#define C1 1
#define C2 1

// Hash function to calculate the hash value for a given key
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert an item into the hash table
bool hashInsert(int item, int hashTable[]) {
    // Calculate the initial hash value
    int index = hash(item);
    int i = 1; // Counter for quadratic probing
    int startIndex = index; // Save the initial index to detect loops for 2nd, 3rd and so on iteration.

    // Loop until an empty slot is found or the table is full
    while (hashTable[index] != EMPTY_SINCE_START && hashTable[index] != EMPTY_AFTER_REMOVAL) {
        // Calculate the next index using quadratic probing
        index = (startIndex + C1 * i + C2 * i * i) % TABLE_SIZE; // Using the StartIndex value as its actual Hash value
        i++;

        // Check if the hash table is full
        if (i >= TABLE_SIZE) {
            return false; // Hash table is full
        }
    }

    // Insert the item into the hash table
    hashTable[index] = item;
    printf("Item %d was inserted successfully.\n", item);
    return true;
}

// Function to remove an item from the hash table
bool hashRemove(int item, int hashTable[]) {
    // Calculate the initial hash value
    int index = hash(item);
    int i = 1; // Counter for quadratic probing
    int startIndex = index; // Save the initial index to detect loops

    // Loop until the item is found or the table is full
    while (hashTable[index] != item) {
        // Calculate the next index using quadratic probing
        index = (index + C1 * i + C2 * i * i) % TABLE_SIZE;
        i++;

        // Check if the item was not found
        if (i >= TABLE_SIZE || index == startIndex) {  
            printf("Item %d was not found and could not be removed.\n", item);
            return false; // Item not found return false
        }
    }

    // Mark the item as removed. Replace the removed item with -2
    hashTable[index] = EMPTY_AFTER_REMOVAL;
    printf("Item %d was removed successfully.\n", item);
    return true;
}

// Function to search for an item in the hash table
int hashSearch(int item, int hashTable[]) {
    // Calculate the initial hash value
    int index = hash(item);
    int i = 1;
    int startIndex = index;

    // Loop until the item is found or the table is full
    while (hashTable[index] != item && hashTable[index] != EMPTY_SINCE_START) {
        // Calculate the next index using quadratic probing
        index = (startIndex + C1 * i + C2 * i * i) % TABLE_SIZE;  // The StartIndex is actual hash value, Index is updated if collusion occurs.
        i++;

        // Check if the item was not found
        if (i >= TABLE_SIZE) {
            printf("Item %d was not found.\n", item);
            return -9; // Item not found
        }
    }

    // Check if the item was found
    if (hashTable[index] == EMPTY_SINCE_START) {
        printf("Item %d was not found.\n", item);
        return -9; // Item not found return -9
    }

    printf("Item %d was found in bucket %d.\n", item, index);
    return index; // Item found in bucket. Return the bucket number.
}

// Function to display the contents of the hash table
void displayHashTable(int hashTable[]) {
    printf("\nThe hash table contents are:\n\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("HashTable[%d] is ", i);
        if (hashTable[i] == EMPTY_SINCE_START) {
            printf("-1\n");
        }
        else if (hashTable[i] == EMPTY_AFTER_REMOVAL) {
            printf("-2\n");
        }
        else {
            printf("%d\n", hashTable[i]);
        }
    }
}

int main() {
    // Initialize the hash table with empty values
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY_SINCE_START;
    }

    // Insert items into the hash table
    hashInsert(32, hashTable);
    hashInsert(63, hashTable);
    hashInsert(16, hashTable);
    hashInsert(3, hashTable);
    hashInsert(23, hashTable);
    hashInsert(11, hashTable);
    hashInsert(64, hashTable);
    hashInsert(99, hashTable);
    hashInsert(42, hashTable);
    hashInsert(49, hashTable);
    hashInsert(48, hashTable);
    hashInsert(21, hashTable);

    // Display the hash table
    printf("\n");
    displayHashTable(hashTable);

    // Remove items from the hash table
    printf("\n");
    hashRemove(32, hashTable);
    hashRemove(11, hashTable);

    // Search for items in the hash table
    hashSearch(64, hashTable); // Searching for 64

    // Insert an item into the hash table
    hashInsert(9, hashTable); // Inserting 9

    // Search for items in the hash table
    hashSearch(48, hashTable); // Searching for 48
    hashSearch(32, hashTable); // Searching for 32

    // Remove items from the hash table
    hashRemove(64, hashTable); // Removing 64
    hashRemove(99, hashTable); // Removing 99

    // Display the hash table
    printf("\n");
    displayHashTable(hashTable);

    return 0;
}
