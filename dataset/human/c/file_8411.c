#include <stdio.h>
#include <stdlib.h>


int main(){
  int n,k;
  char* s;
  scanf("%d",&n);
  s = malloc(sizeof(char)*(n+1));
  scanf("%s %d",s,&k);
  for(int i=0;i<n;i++){
    if(s[i] != s[k-1]){
      s[i] = '*';
    }
    printf("%c",s[i]);
  }
  printf("\n");
  return 0;
}
