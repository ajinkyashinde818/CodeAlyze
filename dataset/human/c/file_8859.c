#include<stdio.h>

int main(){
  int h,w,i,j,flag=1;
  char s[50][50];
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++)
    scanf("%s",s[i]);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s[i][j]=='#'){
        flag=0;
        if(i!=0){
          if(s[i-1][j]=='#') flag=1;
        }
        if(i!=h-1){
          if(s[i+1][j]=='#') flag=1;
        }
        if(j!=0){
          if(s[i][j-1]=='#') flag=1;
        }
        if(j!=w-1){
          if(s[i][j+1]=='#') flag=1;
        }
        if(!flag){
          printf("No\n");
          return 0;
        }
      }
    }
  }
  if(flag) printf("Yes\n");
  else printf("No\n");
}
