#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void){
  int i,j;
  int w,h;
  char s[60][60];
  int a[60][60];
  for(i=0;i<60;i++){
    for(j=0;j<60;j++){
      a[i][j]=0;
    }
  }
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    scanf("%s",s[i]);
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s[i][j]=='#')
	a[i+1][j+1]=1;
      else
	a[i+1][j+1]=0;
    }
  }
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      if(a[i][j]==1){
	if(a[i-1][j]==0 && a[i+1][j]==0 && a[i][j+1]==0 && a[i][j-1]==0){
	  printf("No\n");
	  return 0;
	}
      }
    }
  }
  printf("Yes\n");
  return 0;
}
