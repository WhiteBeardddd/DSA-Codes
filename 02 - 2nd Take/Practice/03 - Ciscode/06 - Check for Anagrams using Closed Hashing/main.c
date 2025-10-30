#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY '~'
#define DELETED '!'
#define MAX 211

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct {
    char elem;
    int frequency;
} Element;

typedef Element Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);
int hash(char elem);

/*********************************/
/*          YOUR TASKS           */
/*********************************/

void insert(Dictionary D, char elem);
void delete(Dictionary D, char elem);
bool isMember(Dictionary D, char elem);
bool isAnagram(char* s, char* t);

int main(void) {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    if (isAnagram(s1, s2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s1, s2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", s1, s2);
    }

    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i].elem = EMPTY;
        D[i].frequency = 0;
    }
}

int hash(char elem) {
    return ((int)elem) % MAX;
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/


void insert(Dictionary D, char elem) {
  // TODO: Implement insert with linear probing
    int indx = hash(elem);
    int start = indx; // for comparing
  
    while(D[indx].elem != EMPTY && D[indx].elem != elem && D[indx].elem != DELETED){
      indx = (indx + 1) % MAX;
      if (indx == start) {
        break; // if full
      } 
    }
  
    if(D[indx].elem == elem){
      D[indx].frequency++;
    }else{
      D[indx].elem = elem;
      D[indx].frequency = 1;
    }
  
}

void delete(Dictionary D, char elem) {
  // TODO: Implement delete with linear probing
    int indx = hash(elem);
    int start = indx; // for comparing
  
    while(D[indx].elem != EMPTY){
      if(D[indx].elem == elem){
        D[indx].frequency--;
        if(D[indx].frequency <= 0){
          D[indx].elem = DELETED;
          D[indx].frequency = 0;
        }
        break;
      }else{
        indx = (indx + 1) % MAX;
        if(start == indx){
          break;
        }
      }
    }
}

bool isMember(Dictionary D, char elem) {
  // TODO: Implement membership check
    int indx = hash(elem);
    int start = indx; // for comparing

    while(D[indx].elem != EMPTY){
      if(D[indx].elem == elem && D[indx].frequency > 0){
        return true;
      }else{
        indx = (indx + 1) % MAX;
        if(start == indx){
          break;
        }
      }
    }
}

bool isAnagram(char* s, char* t) {
    // TODO: Implement anagram checker
    if(strlen(s) != strlen(t)){
      return false;
    }

    Dictionary D;
    initDict(D);

    for(int i = 0; s[i] != '\0'; i++){
      insert(D, s[i]);
    }

    for(int i = 0; t[i] != '\0'; i++){
      if(!isMember(D, t[i])){
        return false;
      }
      delete(D, t[i]);
    }

    for(int i = 0; i < MAX; i++){
      if(D[i].elem != EMPTY && D[i].elem != DELETED && D[i].frequency != 0){
        return false;
      }
    }

    return true;
}




