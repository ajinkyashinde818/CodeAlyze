#include<stdio.h>
int main(){
  char s[52][52]={0};
  int h,w,i,j;
  scanf("%d%d",&h,&w);
  for(i=1;i<=h;i++)scanf("%s",&s[i][1]);
  for(i=1;i<=h;i++)for(j=1;j<=w;j++)if(s[i][j]=='#'&&s[i][j-1]!='#'&&s[i][j+1]!='#'&&s[i-1][j]!='#'&&s[i+1][j]!='#'){printf("No");return 0;}
  printf("Yes");
}
