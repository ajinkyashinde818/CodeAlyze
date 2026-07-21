#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,a=0,b=0,c=0;
    char S[3];
    scanf("%s",&S);
    for(int i=0;i<3;i++){
        if(S[i]=='a'){
            a++;
        }else if(S[i]=='b'){
            b++;
        }else if(S[i]=='c'){
            c++;
        }
    }

    if((a==1)&&(b==1)&&(c==1)){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
