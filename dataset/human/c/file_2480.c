#include<stdio.h>
int main(void){
    int i,a=0,b=0,c=0;
    char s[4];
    scanf("%s",s);
    for(i=0;i<3;i++){
        if(s[i]=='a'){
            a=1;
        }
        if(s[i]=='b'){
            b=1;
        }
        if(s[i]=='c'){
            c=1;
        }
    }
    if(a==1&&b==1&&c==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
