#include<stdio.h>
int main(void){
    char S[3];
    scanf("%s",S);
    int alph[3] = {0};
    for(int i = 0; i < 3; i++){
        alph[S[i]-'a'] += 1;
    }
    
    if(alph[0] == 1 && alph[1] == 1 && alph[2] == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
