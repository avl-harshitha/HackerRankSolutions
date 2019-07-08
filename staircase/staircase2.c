//approach 2
//time complexity O(n)
//space complexity O(n)


#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int no_of_steps(int i, int* memo) {
    if(i < 1)
        return 0;
    if(i <= 2)
        return i;
    if(i == 3)
        return 4;
    if(memo[i - 1] == 0)
        memo[i - 1] = no_of_steps(i - 3, memo) + no_of_steps(i - 2, memo) + no_of_steps(i - 1, memo);
    return memo[i - 1];
}

// Complete the stepPerms function below.
int stepPerms(int n) {
    int* memo = (int*)malloc(sizeof(int) * n);
    for(int i = 0;i < n; i ++) {
        memo[i] = 0;
    }
    return no_of_steps(n, memo);
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s_endptr;
    char* s_str = readline();
    int s = strtol(s_str, &s_endptr, 10);

    if (s_endptr == s_str || *s_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int s_itr = 0; s_itr < s; s_itr++) {
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        int div = (int)(pow(10, 10) + 0.5); 
        int res = stepPerms(n) % (div + 7);

        fprintf(fptr, "%d\n", res);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}
