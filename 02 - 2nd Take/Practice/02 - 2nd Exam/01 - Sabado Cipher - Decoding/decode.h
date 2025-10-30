#ifndef DECODE_H
#define DECODE_H

#include<stdio.h>
#include<stdlib.h>

int* bitmaskToArray(short int word[]);
char* decodeString(int arr[]);
void displayBitPattern(int arr[]);

#endif