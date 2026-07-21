#include<stdio.h>
#include<string.h>

int main(void)
{
 char str1[3];
 char str2[] = "9";

 scanf("%s",str1);

 if(strstr(str1,str2)!=NULL)
 {
   printf("Yes\n");
 }
 else
 {
  printf("No\n");
 }

return 0;
}
