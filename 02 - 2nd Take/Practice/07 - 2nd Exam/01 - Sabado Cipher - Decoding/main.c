#include<stdio.h>
#include<stdlib.h>
#include"decode.h"

int main(){
	//short int word[4]={22863,21792,16961,19524};
	short int word[4]={17729,21074,18766,18259};
	int *arr;
	char *string;
	int choice;


    printf("=== Sabado Cipher ===\n\n");
	printf("Given the following integers, decode the numbers to form the 8 letter word\n");
	printf("%d %d %d %d\n\n",word[0],word[1],word[2],word[3]);

    printf("Enter test case choice: \n");
    printf("1. Convert the decimal integers into a bit vector Array\n");
    printf("2. Decode the String using the converted bit vector Array\n");
    printf("3. Convert and Decode while displaying both\n\nChoice: ");
    scanf("%d", &choice);

    printf("\n");
	switch(choice){
		case 1:
			arr=bitmaskToArray(word);
	        printf("Bit Pattern:\n");
			displayBitPattern(arr);
			free(arr);

			break;

		case 2:
			arr=bitmaskToArray(word);
			string=decodeString(arr);
			printf("\nDecoded Message:");
			printf("\n%s",string);
			free(string);
			break;

		case 3:
			arr=bitmaskToArray(word);
	        printf("Bit Pattern:\n");
			displayBitPattern(arr);
			string=decodeString(arr);
			printf("\n\nDecoded Message:");
			printf("\n%s",string);

			free(arr);
			free(string);

			break;

		default:
			printf("Invalid Choice");
			break;
	}



	return 0;

}