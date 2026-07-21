#include <stdio.h>
#define N 200000
#define INFINITY 2000000000

int main(){
  int R[N];
  int n,max,min,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

  max=-INFINITY;
  min=R[0];

  for(j=1;j<n;j++){
    if(max>R[j]-min) max=max;//最大値の更新
    else max=R[j]-min;

    if(min<R[j]) min=min;//jまでの最小値を保持する
    else min=R[j];
  }

  printf("%d\n",max);

  return 0;
}
