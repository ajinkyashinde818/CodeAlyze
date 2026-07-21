#include<stdio.h>

static const int MAX=200000;



int main(){
  int i;
  int R[MAX],N;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&R[i]);
  int minv=R[0];
  int ans=-2000000000;
  for(i=1;i<N;i++){
    if(ans < R[i]-minv){
      ans=R[i]-minv;
    }
    if(minv > R[i]){
      minv = R[i];
    }
  }
  printf("%d\n",ans);
  return 0;
}
