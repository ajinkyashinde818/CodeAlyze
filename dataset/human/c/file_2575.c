#include<stdio.h>
#include<stdlib.h>

int main(void){

    int i;
    char S[4];
    scanf("%s",S);

    if(S[1] != S[0]){
        if(S[2]!=S[0] && S[2]!=S[1]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }else{
        printf("No\n");
    }


}
