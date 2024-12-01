#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int right[1000] = {};
    int left[1000] = {};
    int right_size = 0;
    int left_size = 0;
    FILE *f = fopen("input.txt", "r");
    int c = 0;
    char first[100] = {};
    char second[100] = {};
    int index = 0;
    int is_first = 1;
    while ((c = getc(f)) != EOF) {
        if (isdigit(c)) {
            if (is_first) {
                first[index] = c;
            } else {
                second[index] = c;
            }
            index++;
        } else {
            if (index > 0) {
                if (is_first) {
                    first[index] = '\0';
                    right[right_size] = atoi(first);
                    right_size++; 
                    is_first = 0;
                } else {
                    second[index] = '\0';
                    left[left_size] = atoi(second);
                    left_size++;
                    is_first = 1;
                }
                index = 0;
                char first[100] = {};
                char second[100] = {};
            }
        }
    }
    fclose(f);
    
    int n = sizeof(right[0])*right_size / sizeof(right[0]);
    qsort(right, n, sizeof(int), compare);
    qsort(left, n, sizeof(int), compare);
    int result = 0;
    for (int i = 0; i < right_size; ++i) {
        result += (abs(right[i] - left[i]));
    }
    printf("result: [%d]\n", result);

    int result2 = 0;
    for (int i = 0; i < right_size; ++i) {
        int right_id = right[i];
        int count = 0;
        for (int j = 0; j < left_size; ++j) {
            if (right_id == left[j]) count++;
        } 
        result2 += right_id * count;
    }
    printf("result2: [%d]", result2);
}
