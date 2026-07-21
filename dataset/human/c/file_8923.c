#include<stdio.h>
int main(){
  int h,w,i,j,b;
  char s[50][50];
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    scanf("%s", s[i]);
  }

  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s[i][j]=='#'){
        b=0;
        if(i>0)if(s[i-1][j]=='#')b=1;
        if(i<h)if(s[i+1][j]=='#')b=1;
        if(j>0)if(s[i][j-1]=='#')b=1;
        if(j<w)if(s[i][j+1]=='#')b=1;
        if(b==0){
          puts("No");
          return 0;
        }
      }
    }
  }
  puts("Yes");
  return 0;
}
