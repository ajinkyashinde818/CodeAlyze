#include <stdio.h>

int main(void){
  char S[10] = {};
  int i, j, k;
  scanf("%s", S);
  if(S[0] != S[1] && S[1] != S[2] && S[2] != S[0]){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}
