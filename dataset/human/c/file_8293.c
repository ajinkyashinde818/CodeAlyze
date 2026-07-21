#include <stdio.h>

int main(void){
  int n, k;
  scanf("%d", &n);
  char s[n];
  scanf("%s", s);
  scanf("%d", &k);

  char point = s[k-1];
  
  for(int i=0; i<n; i++){
    if(s[i]!=point){ s[i]='*';}
  }

  printf("%s \n", s);
  return 0;
}
