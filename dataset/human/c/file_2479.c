#include<stdio.h>
int main(void)
{
  int i=0,i2=0,i3=0,i4=0,i5=0,i6=0;
  char a[3];
  char str1[]="abc";
    char str2[]="acb";
    char str3[]="bac";
    char str4[]="bca";
    char str5[]="cab";
    char str6[]="cba";
  scanf("%s",a);
 
  i= strcmp(a, str1);
   i2= strcmp(a, str2); 
   i3= strcmp(a, str3);
   i4= strcmp(a, str4);
   i5= strcmp(a, str5);
   i6= strcmp(a, str6);
    
     if(i==0||i2==0||i3==0||i4==0||i5==0||i6==0)
       printf("Yes");
  else printf("No");
 

}
