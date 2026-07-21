#include<stdio.h>
int main (void)
{
char S[3];
int i,n=0;
scanf("%s",S);
for(i=0;i<3;i++)
{if(S[i]=='a')
n=n+1;
if(S[i]=='b')
n=n+2;
if(S[i]=='c')
n=n+3;}
if(n==6)
printf("Yes");
else
printf("No");
return 0;
}
