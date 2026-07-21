#include<stdio.h>
#include<string.h>

int main(void)
{
  int n,k;
  char s[20];
  scanf("%d %s %d",&n,s,&k);
  char tmp=s[k-1];
  int len=strlen(s);
  for(int i=0;i<len;i++){
    if(s[i]!=tmp){
      s[i]='*';
    }
  }

  printf("%s\n",s);
  return 0;
}
