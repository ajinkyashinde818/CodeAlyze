#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    return (int)(*(char*)b - *(char*)a);
}

int ascending_compare(const void *a, const void *b){
    return (int)*(char*)a - *(char*)b;
}




int main(void){
    char s[101];
    char t[101];
    int i;

    scanf("%s %s", s, t);

    qsort(s, strlen(s), sizeof(char), ascending_compare);
    qsort(t, strlen(t), sizeof(char), descending_compare);

    for (i = 0; i < strlen(s); i++){
        if (s[i] < t[i]){
            printf("Yes\n");
            return 0;
        }else if (s[i] > t[i]){
            printf("No\n");
            return 0;
        }
    }

    if (strlen(s) == strlen(t)){
        printf("No\n");
        }else{printf("Yes\n");}
    
    
    
    
    
    return 0;
}
