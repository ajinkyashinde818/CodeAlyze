#include <stdio.h>
 int main(void){
  char s[3]={"abc"};
  char d[3]={0};
  int j;
  int count=0,count1=0,count2=0;
  scanf("%s",d);
   for(j=0;j<3;j++){
      if(d[j]=='a')
       count++;
      if(d[j]=='b')
       count1++;
      if(d[j]=='c')
       count2++;
   }
  if(count==1&&count1==1&&count2==1)
  printf("Yes");
  else
  printf("No");
   return 0;
 }
