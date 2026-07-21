#include<stdio.h>

int main()
{
 char s[3];
 char flag[3];  
   scanf("%s",&s);
   for(int i=0;i<3;i++)
   {
    flag[i]=0;
   }
  
   for(int i=0;i<3;i++)
   {
     if(s[i]=='a')
     {
      flag[0]=1;
     }
     if(s[i]=='b')
     {
      flag[1]=1;
     }
     if(s[i]=='c')
     {
      flag[2]=1;
     }
   }
  if(flag[0]==1&&flag[1]==1&&flag[2]==1)
    printf("Yes");
  else
    printf("No");
  
  return 0;
}
