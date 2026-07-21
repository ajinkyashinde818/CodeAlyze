#include <stdio.h>

int main(void)
{
    int i,t=0,k=0,g=0;
    char S[4];

    scanf("%s",S);

    for(i=0;i<3;i++){
       if(S[i]=='a')
         t++;}
    for(i=0;i<3;i++){
       if(S[i]=='b')
         k++;}
    for(i=0;i<3;i++){
       if(S[i]=='c')
         g++;}
    if(t==1 && k==1 && g==1)
      printf("Yes\n");
    else
      printf("No\n");
   return 0;
}
