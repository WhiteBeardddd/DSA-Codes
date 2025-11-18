#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"    // contains definitions for HashTable, CacheEntry, etc.

int main() {
    HashTable search_cache;
    init_cache(&search_cache);

    printf("Google Cache Simulation using Open Hashing Dictionary\n");
    printf("----------------------------------------------------\n");
    printf("Running all test cases automatically...\n");

    for (int i = 1; i <= 5; i++) {
        run_test_case(&search_cache, i);
    }

    printf("\nAll tests completed. Cleaning up allocated memory...\n");
    free_cache(&search_cache);
    printf("Memory successfully freed. Program complete.\n");

    return 0;
}
