#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char str[10];
    char *tok;
    int N, i;
    
    fgets(str, sizeof(str), stdin);
    tok = strtok(str, " ");
    N = atoi(tok);
    tok = strtok(NULL, " ");
    i = atoi(tok);

    printf("%d\n", (N+1-i));
    return 0;
    
}
