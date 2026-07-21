#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char S[55];
    scanf("%s", S);
    int length;
    int i;

    length = strlen(S);
    for (i = 0; i < length - 8; i++){
        printf("%c", S[i]);
    }
    printf("\n");




    return 0;
}
