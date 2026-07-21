#include<stdio.h>

int main(){
  char S[3];
  int a=0,b=0,c=0;
  scanf("%s",S);
  for(int i=0;i<3;i++){
  if(S[i]=='a')a+=1;
    else if(S[i]=='b')b+=1;
    else if(S[i]=='c')c+=1;
  }
  if((a==1)&&(b==1)&&(c==1))printf("Yes");
  else printf("No");
  return 0;
}
