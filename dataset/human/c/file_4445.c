#include<stdio.h>
int main(void){
  int flg=0,n,c,d,i,fd=0,fdd=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&c,&d);
    if(fdd&&fd&&c==d){
      flg=1;
    }
    fdd=fd;
    fd=c==d;
  }
  if(flg) puts("Yes"); else puts("No");
}
