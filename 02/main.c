#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
    int count = 0;
    FILE *f = fopen("input.txt", "r");
    int c = 0;
    char first[10] = {};
    char next[10] = {};
    int index = 0;
    int is_first = 1;
    int a = -1;
    int b = -1;
    int safe = 1;
    int increasing = 1;
    while((c = fgetc(f)) != EOF) {
        if (c == ' ' || c == '\n') {
            if(is_first) {
                safe = 1;
                first[index] = '\0';
                is_first = 0;
                index = 0;
                a = atoi(first);
            } else {
                next[index] = '\0';
                index = 0;
                int check = 0;
                if (b == -1) {
                    check = 1;
                }
                b = atoi(next);
                if (check) {
                    increasing = a - b < 0 ? 1 : 0;
                }   
                printf("|%d - %d = %d| ", a, b, a-b);
                int test = a-b;
                int result = abs(a-b);
                a = b;
                if (result < 1 || result > 3) {
                    safe = 0;
                }
                if ((increasing && (test > 0)) || (!increasing && (test < 0))) {
                    safe = 0;
                }
            }
            if (c == '\n') {
                if (safe) {
                    printf(" SAFE");
                    count++;
                }   
                printf("\n");
                is_first = 1;
                b = -1;
            }
            char first[10] = {};
            char next[10] = {};
        }
        if(isdigit(c)) {
            if(is_first) {
                first[index] = c; 
                index++;
            } else {
                next[index] = c;
                index++;
            }
        }
    }
    fclose(f);
    printf("COUNT [%d]", count);
    return 0;
}
