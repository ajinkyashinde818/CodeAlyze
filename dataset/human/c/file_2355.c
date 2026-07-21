#include<stdio.h>
int main(void)
{
 char s[4];
 int i,count=0,sum=0,fa=0,fb=0,fc=0;
 scanf("%s",s);
  
 while(s[count]!='\0')
 {
  if(fa==0)if(s[count]=='a'){sum++;fa++;}
  if(fb==0)if(s[count]=='b'){sum++;fb++;}
  if(fc==0)if(s[count]=='c'){sum++;fc++;}
   
   count++;
 }

 if(sum==3) printf("Yes");
 else printf("No");
 return 0;
}
