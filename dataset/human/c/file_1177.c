#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int compare_char1(const void *a, const void *b){
    return *(char*)a > *(char*)b;
}
 
int compare_char2(const void *a, const void *b){
    return *(char*)a < *(char*)b;
}
 
int main(int argc, char *argv[]){
    char s[101] = {};
    char t[101] = {};
    scanf("%s", s);
    scanf("%s", t);
    qsort(s, strlen(s), sizeof(char), compare_char1);
    qsort(t, strlen(t), sizeof(char), compare_char2);
    printf("%s\n", strcmp(s, t) < 0 ? "Yes" : "No");
    return 0;
}
