#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"

void init_cache(HashTable *table) {
    for(int i = 0; i < HASH_BUCKETS; i++){
        // table->buckets[i]->next = NULL;
        table->buckets[i] = NULL;
    }    
}

char **lookup_cache(HashTable *table, const char *key) {
    unsigned int index = hash(key);
    // char **ptr;
    CacheEntry *trav = table->buckets[index];
    while (trav != NULL) {
        // trav = table->buckets[getHash]->next; 
        if (strcmp(trav->key, key) == 0) {
            // Cache HIT
            return trav->results;
        }
        trav = trav->next;
    }
    // Cache MISS
    return NULL;
}


// WHAT I DID
// bool insert_cache(HashTable *table, const char *key) {
//     unsigned int getHash = hash(key);
    
//     CacheEntry *trav = table->buckets[getHash];
//     if(trav == NULL){
//         char **getDB = simulate_database_fetch(key);
//         if(getDB != NULL){
//             if(strcmp(*getDB, key) == 0){
//                 // key already exist
//                 return false;
//             }else{
//                 trav = (CacheEntry*)malloc(sizeof(CacheEntry));
//                 // trav->key = (char)getHash;
//                 trav->results = (char**)key;
//                 return true;
//             }
//         }
//     }
    
//     while(trav != NULL){
//         trav = table->buckets[getHash]->next; 
//     }
    
//     trav = (CacheEntry*)malloc(sizeof(CacheEntry));
//     // trav->key = (char)getHash;
//     trav->results = (char**)key;
//     return true;
// }

// WHAT I SHOUDLVE DONE T_T
bool insert_cache(HashTable *table, const char *key) {
    unsigned int index = hash(key);

    // Check if the key already exists (cache HIT)
    CacheEntry *trav = table->buckets[index];
    while (trav != NULL) {
        if (strcmp(trav->key, key) == 0) {
            // Key already exists — skip DB fetch
            return true;
        }
        trav = trav->next;
    }

    // Cache MISS: Fetch from database
    char **results = simulate_database_fetch(key);
    if (results == NULL) {
        // DB returned no results
        return false;
    }

    // Allocate a new cache entry
    CacheEntry *newEntry = (CacheEntry *)malloc(sizeof(CacheEntry));
    if (newEntry == NULL) {
        cleanup_fetched_results(results);
        return false;
    }

    newEntry->key = strdup(key);  // Duplicate key string
    newEntry->results = results;  // Store DB results
    newEntry->next = table->buckets[index]; // Insert at head (open hashing)
    table->buckets[index] = newEntry;

    return true;
}
