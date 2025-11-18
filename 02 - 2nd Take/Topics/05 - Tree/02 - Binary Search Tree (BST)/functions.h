#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *RC;
    struct node *LC;
}NodeSize, *BST;

void initTree(BST* Tree);
void insertElem(BST* Tree, int data);
void deleteElem(BST* Tree, int data);
int deleteMin(BST *root);
void inOrder(BST Tree);
void preOrder(BST Tree);
void postOrder(BST Tree);

void initTree(BST* Tree){
    *Tree = NULL;
}

void insertElem(BST* Tree, int data){
    BST *trav = Tree;
    while(*trav != NULL && (*trav)->data != data){
        trav = (data < (*trav)->data)? &(*trav)->LC: &(*trav)->RC;
    }

    // If data already exists, do nothing
    if (*trav != NULL && (*trav)->data == data) {
        printf("Element %d already exists!, insertElem Failed\n", (*trav)->data);
        return;
    }

    // Allocate new node
    *trav = (BST)malloc(sizeof(NodeSize));
    (*trav)->data = data;
    (*trav)->LC = NULL;
    (*trav)->RC = NULL;
    
    printf("Element %d succesfully inserted!\n", (*trav)->data);
}

int deleteMin(BST *root) {
    BST *trav = root;

    while ((*trav)->LC != NULL) {
        trav = &(*trav)->LC;
    }

    // (*trav) is the smallest node
    int minVal = (*trav)->data;

    BST temp = *trav;
    *trav = (*trav)->RC;   // might be NULL
    free(temp);

    return minVal;
}

void deleteElem(BST* Tree, int data){
    BST* trav = Tree;

    while (*trav != NULL && (*trav)->data != data){
        trav = (data < (*trav)->data)? &(*trav)->LC: &(*trav)->RC;
    }

    if(*trav == NULL) return;

    BST temp = *trav;
    
    if(temp->LC == NULL){
        // Case 1: No left child
        *trav = temp->RC;
        free(temp);
    }
    else if(temp->RC == NULL){
        // Case 2: No right child
        *trav = temp->LC;
        free(temp);
    }else{
        // Case 3 Version 1: Two children 
        // SUCCESSOR RIGHT SUBTREE
        BST *successor = &(*trav)->RC;
        while ((*successor)->LC != NULL)
        {
            successor = &(*successor)->LC;
        }

        (*trav)->data = (*successor)->data;
        BST temp1 = *successor;
        *successor = (*successor)->RC;
        free(temp1);
    }

    // Case 3 Version 2: Two children → use deleteMin()
    // else{
    //     // Replace this node's value with smallest in right subtree
    //     (*trav)->data = deleteMin(&(*trav)->RC);
    // }
}

void inOrder(BST Tree) {
    if (Tree != NULL)
    {
        inOrder(Tree->LC);
        printf("%d ", Tree->data);
        inOrder(Tree->RC);
    }
    
}

void preOrder(BST Tree) {
    if (Tree != NULL)
    {
        printf("%d ", Tree->data);
        preOrder(Tree->LC);
        preOrder(Tree->RC);
    }
    
}

void postOrder(BST Tree) {
    if (Tree != NULL)
    {
        postOrder(Tree->LC);
        postOrder(Tree->RC);
        printf("%d ", Tree->data);
    }
    
}


#endif