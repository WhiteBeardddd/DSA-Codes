# Variation 1 - Bitmask (char holding int value)

This is the most common and space-efficient way to implement a bit vector set. An unsigned `char` (or `int`) is used, and elements are added by setting the corresponding bit using the bitwise OR operator.

| Operations                                                                 | Checklist                                                                                                                                     | Example                                                                                                 |
| :------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------- |     :----------------------------------------------------------------------------------------------------- |
| `void initialize(unsigned char *set);`                                       | Set the entire byte/integer to 0                                                                                                               | `char A = 0;`                                                                                          |
| `void insert(unsigned char *set, int element);`                              | * Safety check: ensure element index is within the bit range <br> * Create a bitmask for the element's position <br> * Perform Bitwise OR assignment | `insert(&A, 1); // A = 2 {1} (00000010)` <br> `insert(&A, 6); // A = 66 {1, 6} (01000010)`                  |
| `void delete(unsigned char *set, int element);`                              | * Safety check: ensure element index is within the bit range <br> * Create a mask for the element's position <br> * Invert the mask (this creates a mask with a 0 at the target bit and 1s everywhere else) <br> * Perform Bitwise AND assignment | `delete(&A, 6); // A = 2 {1} (00000010)` <br> `delete(&A, 1); // A = 0 { } (00000000)`                  |
| `bool find(unsigned char set, int element);`                                 | * Create a mask for the element's position <br> * Use Bitwise AND between the set and the mask                                                  | `find(A, 6); // True (1)` <br> `find(A, 2); // False (0)`                                               |
| `unsigned char union(unsigned char A, unsigned char B);`                    | * The union is achieved by the Bitwise OR operation                                                                                             | `char A = 66; // {1, 6} (01000010)` <br> `char B = 200; // {3, 6, 7} (11001000)` <br> `char C = union(A, B); // C = 202 {1, 3, 6, 7} (11001010)` |
| `unsigned char intersection(unsigned char A, unsigned char B);`             | * The intersection is achieved by the Bitwise AND operation                                                                                   | `char A = 66; // {1, 6} (01000010)` <br> `char B = 200; // {3, 6, 7} (11001000)` <br> `char C = intersection(A, B); // C = 64 {6} (01000000)` |
| `unsigned char difference(unsigned char A, unsigned char B);`               | * The difference is achieved by A AND (NOT B)                                                                                                 | `char A = 66; // {1, 6} (01000010)` <br> `char B = 200; // {3, 6, 7} (11001000)` <br> `char C = difference(A, B); // C = 2 {1} (00000010)` |
| `void display(unsigned char set);`                                          | * Iterate through all possible elements (0 to 7) <br> * Check if the bit corresponding to element is set <br> * If present, print the element, separated by commas | `char A = 202; // {1, 3, 6, 7} (11001010)` <br> `display(A); // Output: 1, 3, 6, 7`                       |

---

### Explanation

1. **`initialize()`**: Resets the entire bit vector (in this case, a `char`) to `0`.
2. **`insert()`**: Adds an element to the set by setting its corresponding bit to `1`. It uses bitwise OR to set the bit.
3. **`delete()`**: Removes an element from the set by setting its corresponding bit to `0`. It inverts the bitmask before applying a bitwise AND.
4. **`find()`**: Checks if an element is present in the set by checking the corresponding bit.
5. **`union()`**: Returns the union of two sets (combined set of elements) using the Bitwise OR operator.
6. **`intersection()`**: Returns the intersection of two sets (common elements) using the Bitwise AND operator.
7. **`difference()`**: Returns the difference between two sets (elements in A but not in B) using A AND (NOT B).
8. **`display()`**: Iterates through all possible elements and displays the ones that are set.

### Notes

- The elements are represented as positions in the bitmask, where each element corresponds to a bit in the byte/integer.
- This method of implementation is compact and efficient, utilizing bitwise operations for set operations.

---
<br><br>
# Variation 2 - Bit fields

Bit fields allow the compiler to pack structure members into a small number of bits. The struct itself holds the bit set.

Example:
```c
typedef struct {
    // 'field: 8' defines 'field' to be exactly 8 bits wide.
    unsigned int field : 8;
} Set;
```
---

| Operations                            | Checklist                                                                                                                                                                | Example                                                                                                     |
| :------------------------------------ | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :---------------------------------------------------------------------------------------------------------- |
| `void initialize(Set *set);`          | * Access the 'field' member of the structure via the pointer <br> * Set the value of this bit field directly to 0, clearing all bits within it                           | `Set A;` <br> `initialize(&A); // A.field = 0`                                                              |
| `void insert(Set *set, int element);` | * Safety check: ensure element index is within the bit range <br> * Create the bitmask <br> * Use Bitwise OR to set the corresponding bit in the 'field' member          | `insert(&A, 0); // A.field = 1` <br> `insert(&A, 4); // A.field = 17` <br> `insert(&A, 5); // A.field = 49` |
| `void delete(Set *set, int element);` | * Safety check: ensure element index is within the bit range <br> * Create the mask and invert it <br> * Use Bitwise AND NOT to clear the corresponding bit in the field | `delete(&A, 5); // A.field = 17` <br> `delete(&A, 4); // A.field = 1` <br> `// Final set: {}`               |
| `bool find(Set set, int element);`    | * Create a mask <br> * Use Bitwise AND to check the status of the corresponding bit in the field                                                                         | `find(A, 4); // True (1)` <br> `find(A, 3); // False (0)`                                                   |
| `Set union(Set A, Set B);`            | * The union is achieved by the Bitwise OR operation                                                                                                                      | `Set A = {49 (4, 5)}` <br> `Set B = {36 (2, 5)}` <br> `Set C = union(A, B); // C.field = 53 {0, 4, 5}`      |
| `Set intersection(Set A, Set B);`     | * The intersection is achieved by the Bitwise AND operation                                                                                                              | `Set A = {49 (4, 5)}` <br> `Set B = {36 (2, 5)}` <br> `Set C = intersection(A, B); // C.field = 32 {5}`     |
| `Set difference(Set A, Set B);`       | * The difference is achieved by A AND (NOT B)                                                                                                                            | `Set A = {49 (4, 5)}` <br> `Set B = {36 (2, 5)}` <br> `Set C = difference(A, B); // C.field = 17 {4}`       |
| `void display(unsigned char set);`    | * Iterate through all possible elements (0 to 7) <br> * Check if the bit corresponding to the element is set <br> * If present, print the element, separated by commas   | `display(A); // Output: {1, 3, 6, 7}`                                                                       |

---

### Explanation

1. **`initialize()`**: Resets the bit field (`field`) to `0`.
2. **`insert()`**: Adds an element to the set by setting its corresponding bit to `1`. It uses Bitwise OR to set the bit.
3. **`delete()`**: Removes an element from the set by clearing its corresponding bit (setting it to `0`). It uses Bitwise AND NOT after inverting the bitmask.
4. **`find()`**: Checks if an element is present in the set by checking its corresponding bit using Bitwise AND.
5. **`union()`**: Combines two sets using Bitwise OR to include all elements from both sets.
6. **`intersection()`**: Finds common elements between two sets using Bitwise AND.
7. **`difference()`**: Returns the difference between two sets (elements in A but not in B) using A AND (NOT B).
8. **`display()`**: Iterates through all possible elements (0 to 7) and displays those that are set (i.e., their corresponding bit is `1`).

### Notes

- Bit fields are packed into the structure with a specified width (in this case, 8 bits), and operations on them are performed using bitwise operators.
- The use of bit fields ensures that memory usage is minimized when only a small number of bits are required for storage.

---
<br><br>


# Variation 3 - Boolean/Enum Array

This implementation uses an array where the index represents the element and the value (`true/false`) represents membership.

Example:
```c
#define ARRAY_SIZE 8

// The set itself is just an array of booleans/integers.
typedef bool Set[ARRAY_SIZE];
```

| Operations                                | Checklist                                                                                                                                                                                        | Example                                                                                                                                          |
| :---------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------- |
| `void initialize(Set set);`               | * Iterate through every index from 0 up to `ARRAY_SIZE - 1` <br> * Set the value at each index to false                                                                                          | `Set A;` <br> `initialize(A); // [0,0,0,0,0,0,0,0]`                                                                                              |
| `void insert(Set set, int element);`      | * Safety check: ensure element index is within the array range <br> * Use the element value as the array index <br> * Set the value to true                                                      | `insert(A, 0); // [1,0,0,0,0,0,0,0]` <br> `insert(A, 2); // [1,0,1,0,0,0,0,0]` <br> `insert(A, 7); // [1,0,1,0,0,0,0,1] // Final set: {0, 2, 7}` |
| `void delete(Set set, int element);`      | * Safety check: ensure element index is within the array range <br> * Use the element value as the array index <br> * Set the value to false                                                     | `delete(A, 0); // [0,0,1,0,0,0,0,1] // Final set: {2, 7}`                                                                                        |
| `bool find(Set set, int element);`        | * Safety check: ensure element index is within the array range <br> * Access the array index corresponding to the element <br> * Return the boolean value (`true` if present, `false` otherwise) | `find(A, 2); // True (1)` <br> `find(A, 5); // False (0)`                                                                                        |
| `void union(Set A, Set B, Set C);`        | * The resulting set (C) stores the union <br> * Iterate through every possible index <br> * Set element true if present in A OR B                                                                | `A = [1,0,1,0,0,0,0,1] // {0,2,7}` <br> `B = [0,1,1,0,1,1,0,0] // {1,2,4,5}` <br> `union(A,B,C); // C = [1,1,1,0,1,1,0,1] {0,1,2,4,5,7}`         |
| `void intersection(Set A, Set B, Set C);` | * The resulting set (C) stores the intersection <br> * Iterate through every possible index <br> * Set element true if present in A AND B                                                        | `A = [1,0,1,0,0,0,0,1] // {0,2,7}` <br> `B = [0,1,1,0,1,1,0,0] // {1,2,4,5}` <br> `intersection(A,B,C); // C = [0,0,1,0,0,0,0,0] {2}`            |
| `void difference(Set A, Set B, Set C);`   | * The resulting set (C) stores the difference <br> * Iterate through every possible index <br> * Set element true only if in A AND NOT in B                                                      | `A = [1,0,1,0,0,0,0,1] // {0,2,7}` <br> `B = [0,1,1,0,1,1,0,0] // {1,2,4,5}` <br> `difference(A,B,C); // C = [1,0,0,0,0,0,0,1] {0,7}`            |
| `void display(Set set);`                  | * Iterate through all possible elements <br> * Print each element where value is true                                                                                                            | `A = [1,0,1,0,0,0,0,1]` <br> `display(A); // Output: 0, 2, 7`                                                                                    |

---

### Explanation

1. **`initialize()`**: Resets all elements in the array to `false`.
2. **`insert()`**: Adds an element to the set by setting the array index corresponding to the element to `true`.
3. **`delete()`**: Removes an element from the set by setting its array index to `false`.
4. **`find()`**: Checks if an element is present in the set by returning the boolean value stored at its array index.
5. **`union()`**: Combines two sets by setting each index in the result to `true` if it is `true` in either set.
6. **`intersection()`**: Finds common elements between two sets by setting each index in the result to `true` only if it is `true` in both sets.
7. **`difference()`**: Returns the elements in A but not in B by setting each index in the result to `true` only if it is `true` in A and `false` in B.
8. **`display()`**: Iterates through all possible indices and prints those that are `true`.

### Notes

- Each element of the set is represented by a **boolean array index**.
- Membership is indicated directly by the value at each index (`true` = present, `false` = absent).
- This approach is simple and easy to understand, but it uses more memory compared to bitmask or bit field implementations.
- Operations run in **O(n)** time since all possible indices may need to be checked.

---
<br><br>
