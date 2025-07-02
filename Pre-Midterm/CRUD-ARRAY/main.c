#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct{
    char FName[24];
    char LName[16];
    char MI;
}NameType;

typedef struct{
    int day; 
    int month; 
    int year;
}DateType;

typedef struct{
    NameType StudName;
    DateType date;
    int ID;
    int year;
}Student;
// Helper Fuctions //
Student populateData(Student newStud);
Student populateData(Student newStud){ // DIRECT ASSINGMENT No Need to pass the address
   printf("\nEnter Student's Name\n");

    printf("First Name: ");
    fgets(newStud.StudName.FName, sizeof(newStud.StudName.FName), stdin);
    newStud.StudName.FName[strcspn(newStud.StudName.FName, "\n")] = 0;

    printf("Last Name: ");
    fgets(newStud.StudName.LName, sizeof(newStud.StudName.LName), stdin);
    newStud.StudName.LName[strcspn(newStud.StudName.LName, "\n")] = 0;

    printf("Middle Initial: ");
    scanf(" %c", &newStud.StudName.MI);
    while (getchar() != '\n'); // Clear leftover input

    return newStud;
}
// insertion //
void insertFirst(Student *s, Student data, int *cnt);
void insertFirst(Student *s, Student data, int *cnt){
    int i;
    if(*cnt < MAX){
        for(i = *cnt; i > 0; i--){
            s[i] = s[i-1];
        }
        s[0] = data;
        (*cnt)++;
    }else{
        printf("List is Full\n");
    }
}
void insertLast();
void insertMiddle();
void insertPosition();
void insertSorted();
void insertUnique(); //element does not exisst yet//

// Deletion //
void deleteFirst(Student *s, int *cnt);
void deleteFirst(Student *s, int *cnt){
    int i;
    if(*cnt > 0){
        for(i = 0; i < *cnt; i++){
            s[i] = s[i + 1];
        }
        (*cnt)--;
    }else{
        printf("Nothing to Delete, List is empty\n");
    }
}
void deleteLast();
void deleteMiddle();
void deletePosition();
void deleteAllOccur();

// Display & Search //
void display(Student s[], int cnt);
void display(Student s[], int cnt){
    if(cnt == 0){
        printf("List is Empty");
    }else{
        for(int i = 0; i < cnt; i++){
            printf("Name %s %c. %s", s[i].StudName.FName, s[i].StudName.MI, s[i].StudName.LName);
        }   
    }
}
void locateElement();

int main(){
    Student student[MAX], data;
    int choice;
    int cnt = 0;

    printf("Student Management System\n");

    while (choice != 5){
        printf("\n==== Student Management System ====\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Update Student\n");
        printf("5. End Program\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); 

        switch (choice){
        case 1:
            data = populateData(data);
            insertFirst(student, data, &cnt);
            break;
        case 2:
            deleteFirst(student, &cnt);
            break;
        case 3:
            display(student, cnt);
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Invalid Choice Try again! \n");
        }
    }

    return 0;
}