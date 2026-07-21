#include <stdio.h>
 
int main(){
  int n;
  scanf("%d\n",&n);
  char s[n];
  for(int i = 0; i < n; ++i) scanf("%c",&s[i]);
  int k;
  scanf("\n%d",&k);
  char bin = s[k-1];
  for(int i = 0; i < n; ++i){
    if(s[i] != bin) s[i] = '*';
  }
  for(int i = 0; i < n; ++i) printf("%c",s[i]);
  printf("\n");
  return 0;
}
