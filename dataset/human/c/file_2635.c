#include<stdio.h>
int main(void)
{
 char s[3];
 int i;
 int a=0,b=0,c=0;
 scanf("%s",&s[0]);
 for(i=0;i<3;i++){
     if(s[i]=='a')
        a++;
     else if(s[i]=='b')
        b++;
     else if(s[i]=='c')
        c++;
 }
 if(a==1&&b==1&&c==1)
    printf("Yes");
 else
    printf("No");
}
