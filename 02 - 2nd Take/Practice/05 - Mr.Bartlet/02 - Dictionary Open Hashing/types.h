#ifndef TYPES_H
#define TYPES_H

// Maximum size of hash table (palette size)
#define PALETTE_SIZE 64
// Maximum length for a color name
#define MAX_NAME_LENGTH 50

// Type definition for a string
typedef char String[MAX_NAME_LENGTH];

// Color Structure
typedef struct {
    String colorName;
    int RGBVal[3]; // [R, G, B] values, each 0-255
} Color;

// Linked List Node Structure
typedef struct Node {
    Color data;
    struct Node *next;
} Node;

// Dictionary Structure (the hash table)
typedef struct {
    Node *buckets[PALETTE_SIZE]; // Array of pointers to the head of each linked list
} Dictionary;

// function prototypes
int hashFunction(int rgb[3]);
void createDictionary(Dictionary *dict);
Node* createNode(Color newColor);
void insertColor(Dictionary *dict, Color newColor);
Color* searchColor(Dictionary *dict, int rgb[3]);

#endif