#include <stdio.h>
#include <string.h>

int main(){
  int alph[3]={0};
  char S[3];
  scanf("%s", S);
  
  for(int i=0;i<=2;i++){
    if(S[i]=='a'){alph[0]=alph[0]+1;}
    else if(S[i]=='b'){alph[1]=alph[1]+1;}
    else if(S[i]=='c'){alph[2]=alph[2]+1;}
  }
  if(alph[0]==1 && alph[1]==1 && alph[2]==1){
    printf("Yes\n");
  }
  else printf("No\n");
  //printf("%s\n", S);
  return 0;
}
