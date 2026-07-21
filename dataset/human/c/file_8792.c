#include<stdio.h>
#include<stdlib.h>
int main(void){
  int H;
  int W;
  scanf("%d",&H);
  scanf("%d",&W);
  char s[H+2][W+2]={0};
  for(int i=1;i<H+1;i++){
    for(int j=1;j<W+1;j++){
      char c;
      scanf("%c",&c);
      if(c=='\n'){
        scanf("%c",&s[i][j]);
      }
      else{
        s[i][j]=c;
      }
    }
  }
  
  for(int i=1;i<H+1;i++){
    for(int j=1;j<W+1;j++){
      if(s[i][j]=='#'){
        if(s[i-1][j]!='#'&&s[i+1][j]!='#'&&s[i][j+1]!='#'&&s[i][j-1]!='#'){
          printf("No");
          exit(0);
        }
      }
    }
  }
  printf("Yes");
    return 0;
}
