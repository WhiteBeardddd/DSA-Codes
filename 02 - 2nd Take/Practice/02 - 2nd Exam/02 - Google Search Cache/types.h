#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

#define HASH_BUCKETS 100
#define RESULT_COUNT 3

// Structure for a single entry in the cache (a Node in the linked list)
typedef struct CacheEntry {
    char *key;                   // The search query string (dynamically allocated)
    char **results;              // Array of result strings (dynamically allocated), size RESULT_COUNT
    struct CacheEntry *next;     // Pointer for separate chaining (Open Hashing)
} CacheEntry;

// Structure for the entire Hash Table
typedef struct {
    CacheEntry *buckets[HASH_BUCKETS];
} HashTable;

// --- Function Prototypes ---
void init_cache(HashTable *table);
char **lookup_cache(HashTable *table, const char *key);
bool insert_cache(HashTable *table, const char *key);

unsigned int hash(const char *str);
void free_cache(HashTable *table);
char **simulate_database_fetch(const char *key);
void cleanup_fetched_results(char **results);
void print_results(const char *key, char **results);
void run_test_case(HashTable *cache, int test_id);

#endif