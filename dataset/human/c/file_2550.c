#include <stdio.h>
int main(){
  char s[3];
  scanf("%s",s);
  int i,counta=0,countb=0,countc=0;
  for(i=0;i<3;i++){
    if(s[i]=='a')
     ++counta;
    if(s[i]=='b')
     ++countb;
    if(s[i]=='c')
     ++countc;
   }
  if(counta==1&&countb==1&&countc==1)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
