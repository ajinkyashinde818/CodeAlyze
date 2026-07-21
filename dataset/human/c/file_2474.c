#include<stdio.h>
int main(void){
  char S[3];
  scanf("%s",&S);
  int i,counta=0,countb=0,countc=0;
  for(i=0;i<3;i++){
    if(S[i]=='a')counta++;
    if(S[i]=='b')countb++;
    if(S[i]=='c')countc++;
  }
  if(counta==1&&countb==1&countc==1)printf("Yes");
  else printf("No");
  return 0;
}
