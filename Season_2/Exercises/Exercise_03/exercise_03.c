#include <stdio.h>
#include "functions.h"

int main() {
    ArrayList AList;
    initAList(&AList);

    // Create some students
    studtype s1 = {"23100750", {"Charles Benedict", "Boquecosa", 'G'}, "CIS-2201", 4};
    studtype s2 = {"23100751", {"Maria", "Santos", 'L'}, "CIS-2201", 3};
    studtype s3 = {"23100752", {"Luke", "Cabahug", 'E'}, "CIS-2203", 2};
    studtype s4 = {"23100753", {"Danni", "German", 'G'}, "CIS-2203", 2};
    studtype s5 = {"23100754", {"Tombi", "Yatake", 'M'}, "CIS-2202", 2};

    // Insert students (unique insert)
    insertLastUniqueArray(&AList, s1);
    insertLastUniqueArray(&AList, s2);
    insertLastUniqueArray(&AList, s3);
    insertLastUniqueArray(&AList, s4);
    insertLastUniqueArray(&AList, s5);

    printf("Original List:\n");
    displayAList(AList);

    // Try deleting s2
    
    printf("After Delete Elem:\n");
    studtype deleted = deleteElemArray(&AList, "23100751");

    displayAList(AList);

    ArrayList newAList = separateCourseArray(&AList, "CIS-2203");

    printf("\nAfter CIS-2203 enrollee separated from list\n");
    displayAList(AList);
    printf("\n");
    displayAList(newAList);

    return 0;
}
