# 🕵️‍♀️ Sabado Cipher

## 📖 Background

Janie is going back to Davao for All Soul's Day, and her boyfriend is there to pick her up from the airport. Her boyfriend asked if there’s anything she would want as a gift when she arrives, and she replies with an encoded message.

This encoded message is a series of 4 integer values that can be converted into an 8-letter word. It’s now up to you to make sure Janie’s boyfriend gets her the correct gift when she arrives.

## 🎯 Objective

Create the three functions necessary for decoding the message in the file decode.c:

``` c

int* bitmaskToArray(short int word[]);
char* decodeString(int arr[]);
void displayBitPattern(int arr[]);

```

## 🧠 Notes

Remember to terminate the string with \0  
The bit vector array is where each index represents a boolean value: 0 or 1  
One character is 8 bits  
Example: The binary 01011001 equals 89 in decimal, which represents the character 'Y'

## 🧩 Decoding Guide

Given the short integer value 22863, it is represented in bits as:

``` shell
0101100101001111
```

Those bits are stored in a bit vector array and converted to represent two letters:

``` plaintext
short int val = 22863;
bit representation: 0101100101001111
letters: YO
```

## 🧪 Sample Output 1

``` plaintext
=== Sabado Cipher ===

Given the following integers, decode the numbers to form the 8 letter word
17729 21074 18766 18259

Enter test case choice:

Convert the decimal integers into a bit vector Array

Decode the String using the converted bit vector Array

Convert and Decode while displaying both

Choice: 1

Bit Pattern:
0100010101000001 0101001001010010 0100100101001110 0100011101010011
```

---

## 🧪 Sample Output 2

``` plaintext
=== Sabado Cipher ===

Given the following integers, decode the numbers to form the 8 letter word
17729 21074 18766 18259

Enter test case choice:

Convert the decimal integers into a bit vector Array

Decode the String using the converted bit vector Array

Convert and Decode while displaying both

Choice: 3

Bit Pattern:
0100010101000001 0101001001010010 0100100101001110 0100011101010011

Decoded Message:
EARRINGS
```