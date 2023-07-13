/*
 ============================================================================
 Name        : SparseArrays.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    int* counter = (int*)malloc(queries_count * sizeof(int)); // Allocate memory for the counter array
    memset(counter, 0, queries_count * sizeof(int)); // Initialize the counter array with zeros

    for (int i = 0; i < strings_count; i++) {
        for (int j = 0; j < queries_count; j++) {
            if (strcmp(strings[i], queries[j]) == 0) {
                counter[j]++;
            }
        }
    }

    *result_count = queries_count; // Set the value of result_count to queries_count
    return counter;
}

int main() {
    char* strArr[] = {"ab", "ab", "bc"};
    char* strQue[] = {"ab", "bc", "cd"};
    int result_count = 0;

    int* strAns = matchingStrings(3, strArr, 3, strQue, &result_count);

    // Accessing and printing the results
    for (int i = 0; i < 3; i++) {
        printf("%d ", strAns[i]);
    }
    printf("\n");

    free(strAns); // Free the dynamically allocated memory

    return 0;
}


