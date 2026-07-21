#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    char S[4];

    scanf("%s", S);

    int t = 0;

    if(strcmp(S, "abc") == 0){
        t = 1;
    }
    if(strcmp(S, "acb") == 0){
        t = 1;
    }
    if(strcmp(S, "bac") == 0){
        t = 1;
    }
    if(strcmp(S, "bca") == 0){
        t = 1;
    }
    if(strcmp(S, "cab") == 0){
        t = 1;
    }
    if(strcmp(S, "cba") == 0){
        t = 1;
    }

    if(t == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
