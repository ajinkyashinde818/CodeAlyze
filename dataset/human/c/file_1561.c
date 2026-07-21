#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[]){

    char x, y;

    scanf("%c %c", &x, &y);

    if(x < y){
        printf("<");
    }else if(x > y){
        printf(">");
    }else{
        printf("=");
    }

    printf("\n");

    return 0;
}
