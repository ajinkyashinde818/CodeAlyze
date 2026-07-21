#include<stdio.h>

int main()
{
 char fest[60];
 int i;
 int count=0;

 scanf("%s",&fest);
 for(i=0;i<55;i++)
 {
  if((fest[i]>='A')&(fest[i]<='Z'))
  {
   count++;
  }else{
   break;
  }
 }

 for(i=0;i<(count-8);i++) printf("%c",fest[i]);
 printf("\n");

 return 0;
}
