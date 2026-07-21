#include<stdio.h>
int main()
{
  int n,h1=0,h2=0,h3=0;
  char S[4];
  
  scanf("%s",S);
  
  for(n=0; n<3; n++){
    if(S[n]=='a'){
      h1++;
    }else if(S[n]=='b'){
      h2++;
    }else if(S[n]=='c'){
      h3++;
    }
  }
  
  if(h1==1 && h2==1){
    if(h3==1){
      printf("Yes");
    }else{
      printf("No");
    }
  }else{
    printf("No");
  }
  
  return 0;
}
