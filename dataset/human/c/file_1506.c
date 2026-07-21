#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char x;
    char y;
    scanf("%c", &x);
    scanf(" %c", &y);

    if (x < y){
        printf("<\n");
    }else if (x == y){
        printf("=\n");
    }else if (x > y){
        printf(">\n");
    }

    return 0;
}
