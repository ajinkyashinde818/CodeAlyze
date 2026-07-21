#include<stdio.h>

int main()
{
  int h,w;
  int i,j;
  char s[51][51];
  scanf("%d%d",&h,&w);
  for(i=0;i<h;i++){
    scanf("%s",s[i]);
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s[i][j]=='.') continue;
      if(0<=i-1){
        if(s[i-1][j]=='#') continue;
      }
      if(0<=j-1){
        if(s[i][j-1]=='#') continue;
      }
      if(j+1<=w-1){
        if(s[i][j+1]=='#') continue;
      }
      if(i+1<=h-1){ 
        if(s[i+1][j]=='#') continue;
      }
      printf("No");
      return 0;
    }
  }
  printf("Yes");
  return 0;
}
