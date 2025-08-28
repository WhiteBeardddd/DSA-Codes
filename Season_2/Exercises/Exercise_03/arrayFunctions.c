#include <stdio.h>
#include "functions.h"

//* Helper Functions for ArrayList *// 

// Initializes the ArrayList by setting the count to 0
// Can also be called as MAKENULL function
void initAList(ArrayList *L){
    L->count = 0;
}

// Displays all students in the ArrayList
void displayAList(ArrayList L){
    if (L.count != 0) {
        printf("\n%-10s %-10s %-5s %-30s\n", "ID", "Course", "Year", "Name");
        printf("--------------------------------------------------------------\n");
        for (int i = 0; i < L.count; i++) {
            printf("%-10s %-10s %-5d %s %c. %s\n",
                   L.studs[i].ID,
                   L.studs[i].course,
                   L.studs[i].yrlevel,
                   L.studs[i].name.FN,
                   L.studs[i].name.MI,
                   L.studs[i].name.LN);
        }
    } else {
        printf("List is empty\n");
    }
}

//* Main Functions for ArrayList *//

// Inserts a student at the first position (index 0) of the list
void insertFirstArray(ArrayList *L, studtype newStud){
    if(L->count == 0){
        // If the list is empty, just put the new student at index 0
        L->studs[0] = newStud;
        L->count++;
    }else if(L->count  < ARR_LENGHT){
        // Shift all existing students one position to the right
        for(int i = L->count; i > 0; i--){
            L->studs[i] = L->studs[i - 1];
        }
        // Place the new student at index 0
        L->studs[0] = newStud;
        L->count++;
    }else{
        // No more space in the array
        printf("The Array is full");
    }
}

// Inserts a student at the end of the list
void insertLastArray(ArrayList *L, studtype newStud){
    if(L->count < ARR_LENGHT){
        // Place the new student at the current last index
        L->studs[L->count] = newStud;
        L->count++;
    }else{
        // No more space in the array
        printf("The Array is full");
    }
}

// Inserts a student at the end only if the ID is unique
void insertLastUniqueArray(ArrayList *L, studtype newStud){
    if(L->count < ARR_LENGHT){
        bool flag = true;
        // Check for duplicate ID
        for(int i = 0; i < L->count; i++){
            if(strcmp(L->studs[i].ID, newStud.ID) == 0){
                flag = false;
                i = L->count; // exit loop or break replacement
            }
        }
        
        if(flag == true){
            // Unique ID, so insert at the end
            L->studs[L->count] = newStud;
            L->count++;
        }else{
            printf("\nElement Exists!, Invalid insert\n");
        }
  
    }else{
        printf("The Array is full");
    }
}

// Inserts a student at a specific position
void insertAtPositionArray(ArrayList *L, studtype newStud, int pos){
    if(L->count == ARR_LENGHT){
        printf("The Array is full");
    }else if(pos < 0 || pos > L->count){
        printf("Invalid Position");
    }else{
        // Shift all elements from pos to the right
        for(int i = L->count; i > pos; i--){
            L->studs[i] = L->studs[i - 1];
        }
        // Insert the new student at the desired position
        L->studs[pos] = newStud;
        L->count++;
    }
}

// Deletes a student by ID and returns the removed student
studtype deleteElemArray(ArrayList *L, char ID[]){
    // Default value if ID not found
    studtype dummy = {"XXXXX", {"XXXXX", "XXXXX", 'X'}, "XXXXX", 0};
    bool found = false;
    if(L->count != 0){
        for(int i = 0; i < L->count; i++){
            if(strcmp(L->studs[i].ID, ID) == 0){
                // Found the student to delete
                dummy = L->studs[i];
                L->count--;
                // Shift all elements after i one position to the left
                for(int j = i; j < L->count; j++){
                    L->studs[j] = L->studs[j + 1];
                }
                found = true;
                i = L->count; // exit loop or break replacement
            }
        }
        if(found == false){
            printf("ID not found");
        }
    }else{
        printf("List is empty");
    }
    return dummy;
}

// Separates all students of a given course into a new list and removes them from the original list
ArrayList separateCourseArray(ArrayList *L, char course[]){
    ArrayList newList;
    initAList(&newList);  // Start with an empty list

    if(L->count != 0){
        int i = 0;
        while(i < L->count){
            if(strcmp(L->studs[i].course, course) == 0){
                // Copy matching student into newList
                // uses count as index, then increments by 1 Note:newList.count++ is (post increment)
                newList.studs[newList.count++] = L->studs[i]; 

                // Remove that student from the original list
                L->count--;
                for(int j = i; j < L->count; j++){
                    L->studs[j] = L->studs[j + 1];
                }
                // Do not increment i here because elements have shifted
            }else{
                // Only move to the next element if nothing was removed
                i++;
            }
        }
    }else{
        printf("List is empty");
    }

    return newList;
}

