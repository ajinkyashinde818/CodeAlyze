// 161-C Replacing Integer

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>

// qsortで用いる比較用関数．*a<*bならaが先になる．
int compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

void kojun(char* word) {
    char min_alphabet[2],tmp[2];
    int i, min_i,j;

    for (j = strlen(word) - 1; j > 0; j--) {
        min_i = 0;
        min_alphabet[0] = word[min_i];
        for (i = 1; i < j+1; i++) {
            if (word[i] < min_alphabet[0]) {
                //printf("word[i]:%c min_alphabet:%c ", word[i], min_alphabet[0]);
                min_alphabet[0] = word[i];
                min_i = i;
            }
        }
        tmp[0] = word[j];
        word[j] = word[min_i];
        word[min_i] = tmp[0];
        
        //printf("j:%d min_alphabet:%c\n", j, min_alphabet[0]);
    }
    return;
}

void syojun (char* word) {
    char max_alphabet[2], tmp[2];
    int i, max_i, j;

    for (j = strlen(word) - 1; j > 0; j--) {
        max_i = 0;
        max_alphabet[0] = word[max_i];
        for (i = 1; i < j + 1; i++) {
            if (word[i] > max_alphabet[0]) {
                //printf("word[i]:%c max_alphabet:%c ", word[i], max_alphabet[0]);
                max_alphabet[0] = word[i];
                max_i = i;
            }
        }
        tmp[0] = word[j];
        word[j] = word[max_i];
        word[max_i] = tmp[0];

        //printf("j:%d max_alphabet:%c\n", j, max_alphabet[0]);
    }
    return;
}


int main() {

    char word_s[101], word_t[101];

    scanf("%s", word_s);
    scanf("%s", word_t);
    

    syojun(word_s);
    kojun(word_t);
    //printf("%s %s\n", word_s, word_t);
    if (strcmp(word_s, word_t) < 0) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    
    return 0;
}
