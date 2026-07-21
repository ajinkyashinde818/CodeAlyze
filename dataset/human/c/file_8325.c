#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char S[11];
    int i,N,K;
    char target;
    scanf("%d",&N);
    scanf("%s",S);
    scanf("%d",&K);
    target = S[K-1];
    //printf("%c\n",target);
    //printf("%d\n",strlen(S));
    for(i=0;i<strlen(S);i++){
        if(S[i] != target){
            S[i] = '*' ;
        }
    }
    printf("%s\n",S);
    return 0;
    
}
