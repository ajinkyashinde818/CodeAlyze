#include<stdio.h>
int main()
{
  int N;
  int D1[101],D2[101];
  scanf("%d",&N);
  for(int i=0;i<N;i++){scanf("%d %d",&D1[i],&D2[i]);}
  int check=0;
  
  for(int i=0;i<N-2;i++){
    if(D1[i]==D2[i] && D1[i+1]==D2[i+1] && D1[i+2]==D2[i+2]){
      check = 1;
      break;
    }
  }
  if(check==0){printf("No");}else{printf("Yes");}
}
