#include<stdio.h>

int main(void){
  int x,y,i,j,k;
  long long int ans=0;
  scanf("%d %d",&x,&y);
  for(i=0;i<=x;i++){
    for(j=0;j<=x;j++){
      if(0<=y-(i+j) && y-(i+j)<=x) ans++;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
