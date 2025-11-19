#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *LC;
    struct node *RC;
} NodeSize, *POT;

void initTree(POT *root);
POT createNode(int data);
bool insertToParent(POT root, int parentVal, int data);
void insertChild(POT *root, int parentVal, int data);
void printPOT(POT root);

// ------------------------------------------------------------

void initTree(POT *root){
    *root = NULL;
}

POT createNode(int data){
    POT newNode = (POT) malloc(sizeof(NodeSize));
    newNode->data = data;
    newNode->LC = NULL;
    newNode->RC = NULL;
    return newNode;
}

// Insert child under parent
void insertChild(POT *root, int parentVal, int data){
    if(*root == NULL){
        *root = createNode(data);   // first insert becomes root
        return;
    }

    if(insertToParent(*root, parentVal, data) == false){
        printf("Parent %d not found!\n", parentVal);
    }
}

// Recursive search for parent
bool insertToParent(POT root, int parentVal, int data){
    if(root == NULL) return false;

    if(root->data == parentVal){
        // PARTIAL ORDER RULE: parent <= child
        if(data < parentVal){
            printf("Partial order violated! %d < %d\n", data, parentVal);
            return true; // stop but do not retry
        }

        // Insert to first available slot
        if(root->LC == NULL){
            root->LC = createNode(data);
            return true;
        }
        else if(root->RC == NULL){
            root->RC = createNode(data);
            return true;
        }
        else{
            printf("Node %d already has 2 children!\n", parentVal);
            return true;
        }
    }

    // Search left then right
    return insertToParent(root->LC, parentVal, data) ||
           insertToParent(root->RC, parentVal, data);
}

void printPOT(POT root){
    if(root != NULL){
        printf("%d ", root->data);
        printPOT(root->LC);
        printPOT(root->RC);
    }
}

#endif
