#include <stdio.h>

int main(void){
  char s[99];
  char c;
  int n,k,i;
  scanf("%d",&n);
  scanf("%s",&s[0]);
  scanf("%d",&k);

  c=s[k-1];
  for(i=0;i<n;i++){
    if(s[i]!=c)
      s[i]='*';
  }
  printf("%s\n",s);
  return 0;
}
