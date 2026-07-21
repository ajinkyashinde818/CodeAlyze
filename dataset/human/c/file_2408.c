#include<stdio.h>
#include<string.h>
int main(void){
    char S[3];
    scanf("%s",S);
    int A=0,B=0,C=0;

    for(int i=0; i<3; i++){
        if(S[i]=='a'){
            A+=1;
        }
        if(S[i]=='b'){
            B+=1;
        }
        if(S[i]=='c'){
            C+=1;
        }
    }
    if(A==1 && B==1 && C==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
