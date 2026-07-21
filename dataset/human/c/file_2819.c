#include <stdio.h>
int main(void){
  int x,y,k,s,i,j,n;
  n = 0;
  scanf("%d %d",&k,&s);
  for(i=0;i<=k;i++){
    x=i;
    for(j=0;j<=k;j++){
      y=j;
      if((s-x-y)<=k && (s-x-y)>=0 ){
	n++;
      }
    }
  }
  printf("%d",n);
}
