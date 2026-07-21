#include<stdio.h>
int main(){
  int h,w,i,j;
  scanf("%d%d",&h,&w);
  char s[h+2][w+2];
  for(j=0;j<w+2;j++){
    s[0][j]='.';
    s[h+1][j]='.';
  }
  for(i=1;i<h+1;i++){
    for(j=0;j<w+1;j++)
      scanf("%c",&s[i][j]);
    s[i][0]='.';
    s[i][w+1]='.';
  }
  for(i=1;i<h+1;i++)
    for(j=1;j<w+1;j++)
      if(s[i][j]=='#' && s[i-1][j]=='.' && s[i+1][j]=='.' && s[i][j-1]=='.' && s[i][j+1]=='.'){
        puts("No");
        return 0;
      }
  puts("Yes");
  return 0;
}
