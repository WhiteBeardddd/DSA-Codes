#include<stdio.h>
#include<stdlib.h>
#include"decode.h"


int* bitmaskToArray(short int word[]){
    int totalBits = 4 * 16;
    int *arr = (int*)malloc(totalBits *sizeof(int));
    
    if(arr != NULL){
        int index = 0;
        // 4 is the n elements of word[]
        for(int i = 0; i < 4; i++){
            for(int bit = 15; bit >= 0; bit--){
                arr[index++] = (word[i] >> bit) & 1;
            }
        }
        
        return arr;
    }else{
        printf("Memory allocation failed.\n");
        return NULL;
    }
}

char* decodeString(int arr[]){
    int numChars = 8; // total of 64 bits -> 8 characters (char) is 1 byte == 8bits
    char *decoded = (char*)malloc((numChars + 1) * sizeof(char)); // + 1 for null terminator since it will be a decodeString
    if(decoded != NULL){
        for(int i = 0; i < numChars; i++){
            unsigned char value = 0;
            for(int bit = 0; bit < 8; bit++){
                value = (value << 1) | arr[i * 8 + bit];
            }
            decoded[i] = (char)value;
        }
        // last index
        decoded[numChars] = '\0';
            
        return decoded;
    }else{
        printf("Memory allocation failed.\n");
        return NULL;
    }
}

void displayBitPattern(int arr[]){
    for(int i = 0; i < 64; i++){
        printf("%d", arr[i]);
        if((i + 1) % 16 == 0 && i != 63){
            printf(" ");
        }
    }
}

// Write your functions here...