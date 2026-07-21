#include<stdio.h>
int main(){
  int unused __attribute__((unused));
  char S[4];
  unused = scanf("%s", S);

  if(S[0]!=S[1] && S[1]!=S[2] && S[0]!=S[2]) printf("Yes");
  else printf("No");
  return 0;
}
