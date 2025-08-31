# Linked List Exercise

## A) Declare and Visualize List

- Declare a variable of type `charList` and determine its memory allocation.
- Assume the list is populated with **3 elements**.
- Draw the linked list showing each node with:

  - **Name**
  - **Value**
  - **Address**

---

## B) Function: `findElem()`

### Specification

- Given a linked list and an element `X`, the function `findElem()` will return **true** if element `X` is in the list; otherwise, return **false**.
- Uses `stdbool.h` for the `bool` data type (`true` and `false`).

### Constraints

- Only **1 return statement**
- No **break** or **continue** statements

### Tasks

1. Write an appropriate **function header** for `findElem()`.
2. Write an appropriate **function call**, declaring and initializing variables before the call (no garbage values).
3. Draw the **execution stack (call stack)** representing the function call.  
   Each variable should be shown with its **name, value, and address** (use arbitrary addresses such as `A100`, `B100`, etc.).
4. Write the **code** of the function `findElem()`.
5. **Simulate** the function using the following test cases:
   - a) List is empty
   - b) List is not empty and element `X` is in the list
   - c) List is not empty and element `X` is not in the list

---

## C) Function: `deleteElem()`

### Specification

- Given a linked list and an element `X`, the function `deleteElem()` will remove the **first occurrence** of element `X` from the list.

### Constraints

- No **break** or **continue** statements

### Tasks

- Perform the same **5 steps as in Part B**.

### Modified Test Cases

1. List is not empty and element `X` is at the:
   - i) **first position**
   - ii) **last position**
   - iii) **middle position**
2. List is not empty and element `X` is **not in the list**
3. List is empty

---

## D) Function: `deleteAllOccur()`

### Specification

- Given a linked list and an element `X`, the function `deleteAllOccur()` will remove **all occurrences** of element `X` from the list.

### Constraints

- No **break** or **continue** statements

### Tasks

1. Perform **steps 1–4 in Part B**
2. Use the **test cases from Part C**

---

## Notes

- Use proper **memory management** practices when inserting or deleting nodes.
- Ensure that **test cases cover edge cases**:
  - Empty list
  - Element not found
  - Element at head or tail
- Document your code with **comments for clarity**.
- When drawing the linked list or stack, indicate both **values and addresses** for each node.

