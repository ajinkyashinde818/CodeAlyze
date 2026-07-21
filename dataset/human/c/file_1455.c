#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,D,E,x,y,cou=0,v[3];
    char S[3],s[3],X,Y;
    scanf("%d",&A);
    if(A/10==9){
        printf("Yes");
    }else if(A%10==9){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
