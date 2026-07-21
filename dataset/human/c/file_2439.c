#include <stdio.h>

int main(void){
    char s[3];
    int i,s0=0,s1=0,s2=0;

    scanf("%s",s);
    if(s[0]=='a'||s[1]=='a'||s[2]=='a')s0++;
    if(s[0]=='b'||s[1]=='b'||s[2]=='b')s1++;
    if(s[0]=='c'||s[1]=='c'||s[2]=='c')s2++;

    if(s0+s1+s2==3){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
