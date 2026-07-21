#include<stdio.h>

int main(void){
  char S[3];
  int ans=0;
  scanf("%s",S);
  
  if(S[0]==S[1])
    ans=1;
  else if(S[1]==S[2])
    ans=1;
  else if(S[0]==S[2])
    ans=1;
  
  if(ans==0)
    printf("Yes\n");
  else 
    printf("No\n");



  return 0;
}
