#include<stdio.h>

#define N 200000
int main(){

  int max;
  int min;
  int R[N];
  int i, j;
  int n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

  

  for(j=1;j<=n-1;j++){
    for(i=0;i<=j-1;i++){
      if(max<R[j]-R[i]){
	max=R[j]-R[i];
      }
    }
  }

  min=R[0];
  max=R[1]-R[0];
  for(j=1;j<=n-1;j++){
    if(max<R[j]-min){
      max=R[j]-min;
    }
    if(min>R[j]){
      min=R[j];
    }
  }

  printf("%d\n",max);






  return 0;
}
