# 🎨 RGB Dictionary - Open Hashing  
**by Edwin Bartlett**

---

## 🧩 Problem Statement
Create a **C program** that inserts, deletes, and searches RGB values in an **open hashing dictionary** using an **array of linked list** implementation.

All you have to do is write the following functions inside `dict.c`.  
The **main function** and **struct definitions** are already provided.

---

## 🧠 Functions to Implement

### 1. `hashFunction()`
A weighted sum of the R, G, and B components is calculated,  
and the result is constrained by the constant **`PALETTE_SIZE`**.

### 2. `createDictionary()`
Initializes the hash table by setting all **64 bucket pointers** to `NULL`.

### 3. `createNode(Color)`
Allocates memory for a new node and initializes it with the provided `Color` data.

### 4. `insertColor()`
Calculates the hash index and inserts the new Color node  
**at the head** of the corresponding linked list (chaining method).

### 5. `searchColor()`
Calculates the hash index, then traverses the linked list at that index.  
Performs a full RGB value comparison to find the correct entry among potential collisions.

---

## 💡 Tips

### `hashFunction(int rgb[3])`
- Use the following **prime multipliers** to minimize collisions:
  - R × **3**
  - G × **5**
  - B × **7**
- Apply **modulo (`%`)** with the size of the hash table.

---

### `createDictionary(Dictionary *dict)`
- Iterate through all buckets (index `0` to `PALETTE_SIZE - 1`)
- Set each element’s value to `NULL`.

---

### `createNode(Color newColor)`
- Allocate memory for a new node and set its data fields.
- Use `strcpy()` to copy the color name string properly.

---

### `insertColor(Dictionary *dict, Color newColor)`
- Compute the index using `hashFunction()`.
- Create a new node using `createNode()`.
- Insert it **at the head** of the corresponding list.

---

### `searchColor(Dictionary *dict, int rgb[3])`
- Compute the index using `hashFunction()`.
- Traverse the list at that index.
- Check if **R**, **G**, and **B** match exactly.

---

## 🧾 Sample Output

```plaintext
--- Inserting Colors ---
-> Inserted 'Red' (RGB: 255, 0, 0) into bucket [61].
-> Inserted 'Green' (RGB: 0, 255, 0) into bucket [59].
-> Inserted 'Blue' (RGB: 0, 0, 255) into bucket [57].
-> Inserted 'White' (RGB: 255, 255, 255) into bucket [49].
-> Inserted 'Black' (RGB: 0, 0, 0) into bucket [0].
-> Inserted 'Dark Grey' (RGB: 10, 10, 10) into bucket [22].
-> Inserted 'Dark Red' (RGB: 30, 0, 0) into bucket [26].

--- Inserting Colliding Colors ---
-> Inserted 'Light Grey' (RGB: 1, 1, 1) into bucket [15].
-> Inserted 'Slightly Red' (RGB: 5, 0, 0) into bucket [15].

--- Color Dictionary Content ---
Bucket [0]: Black (0,0,0)
Bucket [15]: Slightly Red (5,0,0) -> Light Grey (1,1,1)
Bucket [22]: Dark Grey (10,10,10)
Bucket [26]: Dark Red (30,0,0)
Bucket [49]: White (255,255,255)
Bucket [57]: Blue (0,0,255)
Bucket [59]: Green (0,255,0)
Bucket [61]: Red (255,0,0)

--- Search Results ---
Searching for RGB (255, 0, 0) in bucket [61]...
SUCCESS: Found Color: Red
Searching for RGB (5, 0, 0) in bucket [15]...
SUCCESS: Found Color: Slightly Red
Searching for RGB (255, 165, 0) in bucket [54]...
FAILURE: Color not found.
```

---

## 📘 Summary
This project demonstrates:
- The **use of open hashing (separate chaining)**.
- How to handle **collisions** using linked lists.
- The importance of **a good hash function** for minimizing collisions.
- Practical use of **pointers, structs, and dynamic memory allocation** in C.

---
