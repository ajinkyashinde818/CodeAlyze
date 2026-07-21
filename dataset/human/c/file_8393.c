#include <stdio.h>
#include <string.h>
int main(){
  int len,k,n;
  char s[11],c;
  scanf("%d\n%s\n%d",&n,s,&k);
  c=s[k-1];
  len=strlen(s);
  for (int i=0;i<len;i++){
    if (s[i]!=c) s[i]='*';
  }
  printf("%s\n",s);
  return 0;
}
