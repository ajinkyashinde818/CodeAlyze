#include<stdio.h>
#define M 200000
int main(){
  int i,n,R[M];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  int maxv=-2000000000;
  int minv=R[0];
  for(i=1;i<n;i++){
    if(maxv<R[i]-minv){
      maxv=R[i]-minv;
    }
    if(minv>R[i]){
      minv=R[i];
    }
  }
  printf("%d\n",maxv);
  return 0;
}
