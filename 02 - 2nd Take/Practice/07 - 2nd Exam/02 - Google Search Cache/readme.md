# 🔍 [E2] Google Search Cache  
**by Edwin Bartlett**

---

## 💡 Overview

OMG. Google is secretly low on budget!  
That's why they decided to replace their **expensive caching system** with a cheap alternative — and they’re turning to **students like you** to create their new caching system.  

Can you do it?  
Of course you can, thanks to the incredible things you’ve learned in school!

---

## ⚙️ System Description

Use an **Open Hashing Dictionary** to store **search query strings**.  
Each search query string is associated with an **array of search results**.  

Using this caching system, search results will now be served **much faster** to users — rather than querying the database every single time!

---

## 🧩 Core Operations

- **Lookup** → “Check if this key exists”  
- **Insertion** → “Store this new key/value”

---

## 🧠 Function Specifications

### `void init_cache(HashTable *table)`
Initializes the hash table, setting all buckets to `NULL`.

---

### `char **lookup_cache(HashTable *table, const char *key)`
- Looks up a key in the cache.  
- Returns a pointer to the internal result array (**size 3**) if found (**CACHE HIT**), otherwise returns `NULL`.

---

### `bool insert_cache(HashTable *table, const char *key)`
- Attempts to insert a new key/value pair into the cache.  
- If the key already exists → insertion is **skipped**.  
- If the key is new → it calls `simulate_database_fetch()` to get the results.  
- Returns:
  - `true` → on successful insertion or skipped (existing key)
  - `false` → on failure

---

### `char **simulate_database_fetch(const char *key)`
- Simulates an **expensive database query** to get results.  
- Returns a dynamically allocated array of result strings, or `NULL`.  
- This function is **GIVEN** — all you need to do is **CALL** it.

---

## 🧪 Sample Output 1

``` plaintext
Google Cache Simulation using Open Hashing Dictionary

Note: Test Cases 2 and 3 require Test 1 to be run first.

Select a test case to run:

Run Test 1: New Key Insertion (famous cse concepts)

Run Test 2: Existing Key Lookup (Expected HIT)

Run Test 3: Redundant Insertion (Expected SKIP)

Run Test 4: Second New Key Insertion (latest google earnings report)

Run Test 5: Non-existent Key (DB No Results)

Exit and Free Memory
Enter choice: 1

--- Test 1: New Key Insertion (famous cse concepts) ---
[Lookup Status] Key 'famous cse concepts' MISS. Attempting to fetch and insert (DB QUERY in progress)...
[Insert Status] Insertion successful (DB fetched and cached).
Search results for 'famous cse concepts' (3 results):

Big O Notation: Analyzing Algorithm Efficiency

Turing Machine: The Theoretical Model of Computation

B+ Tree Indexing: Optimizing Database Lookups

Select a test case to run:

Run Test 1: New Key Insertion (famous cse concepts)

Run Test 2: Existing Key Lookup (Expected HIT)

Run Test 3: Redundant Insertion (Expected SKIP)

Run Test 4: Second New Key Insertion (latest google earnings report)

Run Test 5: Non-existent Key (DB No Results)

Exit and Free Memory
Enter choice: 0

--- Cache memory successfully freed. ---
```


---

## 🧪 Sample Output 2
``` plaintext
Google Cache Simulation using Open Hashing Dictionary

Note: Test Cases 2 and 3 require Test 1 to be run first.

Select a test case to run:

Run Test 1: New Key Insertion (famous cse concepts)

Run Test 2: Existing Key Lookup (Expected HIT)

Run Test 3: Redundant Insertion (Expected SKIP)

Run Test 4: Second New Key Insertion (latest google earnings report)

Run Test 5: Non-existent Key (DB No Results)

Exit and Free Memory
Enter choice: 1

--- Test 1: New Key Insertion (famous cse concepts) ---
[Lookup Status] Key 'famous cse concepts' MISS. Attempting to fetch and insert (DB QUERY in progress)...
[Insert Status] Insertion successful (DB fetched and cached).
Search results for 'famous cse concepts' (3 results):

Big O Notation: Analyzing Algorithm Efficiency

Turing Machine: The Theoretical Model of Computation

B+ Tree Indexing: Optimizing Database Lookups

Select a test case to run:

Run Test 1: New Key Insertion (famous cse concepts)

Run Test 2: Existing Key Lookup (Expected HIT)

Run Test 3: Redundant Insertion (Expected SKIP)

Run Test 4: Second New Key Insertion (latest google earnings report)

Run Test 5: Non-existent Key (DB No Results)

Exit and Free Memory
Enter choice: 2

--- Test 2: Existing Key Lookup (famous cse concepts) ---
[Lookup Status] Key 'famous cse concepts' HIT. Returning cached results.
Search results for 'famous cse concepts' (3 results):

Big O Notation: Analyzing Algorithm Efficiency

Turing Machine: The Theoretical Model of Computation

B+ Tree Indexing: Optimizing Database Lookups

Select a test case to run:

Run Test 1: New Key Insertion (famous cse concepts)

Run Test 2: Existing Key Lookup (Expected HIT)

Run Test 3: Redundant Insertion (Expected SKIP)

Run Test 4: Second New Key Insertion (latest google earnings report)

Run Test 5: Non-existent Key (DB No Results)

Exit and Free Memory
Enter choice: 0

--- Cache memory successfully freed. ---
```

## 🧪 Sample Output 3
``` plaintext
Google Cache Simulation using Open Hashing Dictionary

Note: Test Cases 2 and 3 require Test 1 to be run first.

Select a test case to run:

Run Test 1: New Key Insertion (famous cse concepts)

Run Test 2: Existing Key Lookup (Expected HIT)

Run Test 3: Redundant Insertion (Expected SKIP)

Run Test 4: Second New Key Insertion (latest google earnings report)

Run Test 5: Non-existent Key (DB No Results)

Exit and Free Memory
Enter choice: 1

--- Test 1: New Key Insertion (famous cse concepts) ---
[Lookup Status] Key 'famous cse concepts' MISS. Attempting to fetch and insert (DB QUERY in progress)...
[Insert Status] Insertion successful (DB fetched and cached).
Search results for 'famous cse concepts' (3 results):

Big O Notation: Analyzing Algorithm Efficiency

Turing Machine: The Theoretical Model of Computation

B+ Tree Indexing: Optimizing Database Lookups

Select a test case to run:

Run Test 1: New Key Insertion (famous cse concepts)

Run Test 2: Existing Key Lookup (Expected HIT)

Run Test 3: Redundant Insertion (Expected SKIP)

Run Test 4: Second New Key Insertion (latest google earnings report)

Run Test 5: Non-existent Key (DB No Results)

Exit and Free Memory
Enter choice: 3

--- Test 3: Redundant Insertion Test (famous cse concepts) ---
[Insert Status] Insertion was logically skipped because key 'famous cse concepts' already exists.
Note: No DB fetch occurred. Cache results are unchanged.
Search results for 'famous cse concepts' (3 results):

Big O Notation: Analyzing Algorithm Efficiency

Turing Machine: The Theoretical Model of Computation

B+ Tree Indexing: Optimizing Database Lookups

Select a test case to run:

Run Test 1: New Key Insertion (famous cse concepts)

Run Test 2: Existing Key Lookup (Expected HIT)

Run Test 3: Redundant Insertion (Expected SKIP)

Run Test 4: Second New Key Insertion (latest google earnings report)

Run Test 5: Non-existent Key (DB No Results)

Exit and Free Memory
Enter choice: 0

--- Cache memory successfully freed. ---
```