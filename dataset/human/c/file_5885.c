#include<stdio.h>
#include<math.h>
#define MAX 200000

int main(){
  int R[MAX],n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&R[i]);

  int maxv=-INFINITY;
  int minv=R[0];

  for(i=1;i<n;i++){
    if(maxv<R[i]-minv)maxv=R[i]-minv;

    if(minv>R[i])minv=R[i];
  }
  printf("%d\n",maxv);
  return 0;
}
