#include<stdio.h>
int Y[]={1,0,-1,0};
int X[]={0,1,0,-1};
int main(){
  int w,h,i,j,k;
  char s[110][110]={};
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++)scanf("%s",s[i+1]+1);
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      if(s[i][j]-'#')continue;
      for(k=0;k<4;k++){
	if(s[i+Y[k]][j+X[k]]=='#')goto NEXT;
      }
      printf("No\n");
      return 0;
    NEXT:;
    }
  }
  printf("Yes\n");
  return 0;
}
