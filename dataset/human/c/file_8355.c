#include <stdio.h>

int main(){
  int n,k;
  char s[10];
  char ast;
  int i;
  scanf("%d",&n);
  scanf("%s",s);
  scanf("%d",&k);
  //printf("%d %d %s\n",n,k,s);
  ast = s[k-1];
  for(i = 0;i<n;++i){
    if(s[i] != ast){
      s[i] = '*';
    }
  }
  printf("%s\n",s);
  return 0;
}
