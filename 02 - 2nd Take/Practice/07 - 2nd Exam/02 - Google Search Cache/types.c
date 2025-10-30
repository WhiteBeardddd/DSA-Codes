#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"

// Simple hash function (djb2 variant)
unsigned int hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_BUCKETS;
}

// Simulate fetching results from a database (pretend DB)
char **simulate_database_fetch(const char *key) {
    char **results = malloc((RESULT_COUNT + 1) * sizeof(char *));
    if (results == NULL) return NULL;

    if (strcmp(key, "famous cse concepts") == 0) {
        results[0] = strdup("Object-Oriented Programming");
        results[1] = strdup("Data Structures and Algorithms");
        results[2] = strdup("Operating Systems");
    } 
    else if (strcmp(key, "latest google earnings report") == 0) {
        results[0] = strdup("Q3 revenue up 12%");
        results[1] = strdup("Strong cloud growth");
        results[2] = strdup("Ad sales steady");
    } 
    else if (strcmp(key, "ai trends 2025") == 0) {
        results[0] = strdup("Generative AI growth");
        results[1] = strdup("AI-powered cybersecurity");
        results[2] = strdup("Smarter edge devices");
    } 
    else {
        // Unknown key, return NULL
        free(results);
        return NULL;
    }

    results[RESULT_COUNT] = NULL; // Mark end
    return results;
}

// Print the results from cache or DB
void print_results(const char *key, char **results) {
    printf("\nResults for \"%s\":\n", key);
    if (results == NULL) {
        printf("  [No results found]\n");
        return;
    }

    for (int i = 0; results[i] != NULL; i++) {
        printf("  -> %s\n", results[i]);
    }
}

// Clean up memory allocated for fetched results
void cleanup_fetched_results(char **results) {
    if (results == NULL) return;

    for (int i = 0; results[i] != NULL; i++) {
        free(results[i]);
    }
    free(results);
}

// Free all memory used by the cache
void free_cache(HashTable *table) {
    for (int i = 0; i < HASH_BUCKETS; i++) {
        CacheEntry *curr = table->buckets[i];
        while (curr != NULL) {
            CacheEntry *temp = curr;
            curr = curr->next;

            free(temp->key);
            cleanup_fetched_results(temp->results);
            free(temp);
        }
        table->buckets[i] = NULL;
    }

    printf("\n[Cache cleared successfully]\n");
}

// Automated test cases
void run_test_case(HashTable *cache, int test_id) {
    const char *key;

    switch (test_id) {
        case 1:
            key = "famous cse concepts";
            break;
        case 2:
            key = "latest google earnings report";
            break;
        case 3:
            key = "ai trends 2025";
            break;
        case 4:
            key = "nonexistent topic";
            break;
        default:
            printf("Invalid test ID.\n");
            return;
    }

    printf("\n[Test %d] Searching for: \"%s\"\n", test_id, key);

    char **results = lookup_cache(cache, key);
    if (results != NULL) {
        printf("Cache HIT!\n");
        print_results(key, results);
    } else {
        printf("Cache MISS. Fetching from database...\n");
        if (insert_cache(cache, key)) {
            results = lookup_cache(cache, key);
            printf("Fetched and inserted into cache.\n");
            print_results(key, results);
        } else {
            printf("No data found for '%s'.\n", key);
        }
    }
}
