#include<stdio.h>
int main(){
  char S[3];
  int i;
  int aa=0;
  int bb=0;
  int cc=0;

 scanf("%s",&S[0]);
 for(i=0;i<3;i++){
 if(S[i]=='a')
   aa=1;
   if(S[i]=='b')
   bb=1;
   if(S[i]=='c')
   cc=1;
 }
  if(aa==1&&bb==1&&cc==1)
    printf("Yes");
  else
    printf("No");
return 0;
}
