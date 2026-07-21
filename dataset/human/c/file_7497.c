#include<stdio.h>
#define N 10000
int main(){
  int i,j,x[N],cnt=1,n=0;
  for(i=0;i<N;i++){
    scanf("%d",&x[i]);
    if(x[i]==0) break;
    n++;
  }
  for(i=0;i<n;i++){
    printf("Case %d: %d\n",cnt,x[i]);
    cnt++;
  }
  return 0;
}
