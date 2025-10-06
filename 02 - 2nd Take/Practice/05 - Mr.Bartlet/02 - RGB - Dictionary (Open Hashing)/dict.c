#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// Write your functions here...

int hashFunction(int *rgb){
    return ((rgb[0] * 3) + (rgb[1] * 5) + (rgb[2] * 7)) % PALETTE_SIZE;
}

void createDictionary(Dictionary *dict){
    for(int i = 0; i < PALETTE_SIZE; i++){
        dict->buckets[i] = NULL;
    }
}

Node* createNode(Color newColor){
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data.colorName, newColor.colorName);
    for(int i = 0; i < 3; i++){
        newNode->data.RGBVal[i] = newColor.RGBVal[i];
    }
    
    return newNode;
}

void insertColor(Dictionary *dict, Color newColor){
    int hash = hashFunction(newColor.RGBVal);
    if(hash < PALETTE_SIZE){
        Node* newNode = createNode(newColor);
        if(dict->buckets[hash] != NULL){
            printf("-> Inserted '%s' (RGB: %d, %d, %d) into bucket [%d].\n",newColor.colorName, newColor.RGBVal[0], newColor.RGBVal[1], newColor.RGBVal[2], hash);
            newNode->next = dict->buckets[hash];
            dict->buckets[hash] = newNode;
        } else {
            printf("-> Inserted '%s' (RGB: %d, %d, %d) into bucket [%d].\n",newColor.colorName, newColor.RGBVal[0], newColor.RGBVal[1], newColor.RGBVal[2], hash);
            dict->buckets[hash] = newNode;
        }
    }
}

Color* searchColor(Dictionary *dict, int rgb[3]){
    int hash = hashFunction(rgb);
    Node* trav = dict->buckets[hash];
    printf("Searching for RGB (%d, %d, %d) in bucket [%d]...\n", rgb[0], rgb[1], rgb[2], hash);
    for(int searchCheck = 0; trav != NULL; trav = trav->next){
        searchCheck = 0;
        for(int i = 0; i < 3; i++){
            if(trav->data.RGBVal[i] == rgb[i]){
                searchCheck++;
            }
        }
        if(searchCheck == 3){
            return &trav->data;
        }
    }
    return NULL;
}