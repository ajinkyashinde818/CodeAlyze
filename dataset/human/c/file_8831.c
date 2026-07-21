#include<stdio.h>


int main(){
  int i,j,k;
  int H,W;
  scanf("%d %d",&H,&W);
  char S[H+2][W+2];
  for(i=0;i<H+2;i++){
    for(j=0;j<W+2;j++)
      S[i][j] = '.';
  }
  for(i=1;i<=H;i++){
    scanf("%s",S[i]);
  }
  
  for(i=1;i<=H;i++){
    for(j=1;j<=W;j++){
      if(S[i][j]=='#'){
        if(!(S[i+1][j] == '#' || S[i-1][j] == '#' || S[i][j+1] == '#' || S[i][j-1] == '#')){
          puts("No");
          return 0;
        }
      }
    }
  }
  puts("Yes");
  return 0;
}
