#include<stdio.h>
#include<string.h>
int min(int a,int b){return(a<b)?a:b;}
int main(void)
{
  int a=0,b=1,c,i=0;char s[1000005];
  if(scanf("%s",s)==1)
  {
    while(i<strlen(s)){c=a;a=min(a+s[i]-48,b+58-s[i]);b=min(c+s[i]-47,b+57-s[i]);i++;}
    return printf("%d",a),0;
  }
  else return 0;
}
