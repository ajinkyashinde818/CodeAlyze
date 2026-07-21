#include<stdio.h>

#define MAX 200005

int main(){
  int i;
  int n,A[MAX];
  int maxv,minv=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  minv = A[0];
  maxv = A[1]-A[0];
  for(i=1;i<n;i++){
    if(maxv < A[i]-minv){
      maxv=A[i]-minv;
    }
    if(minv > A[i]){
      minv=A[i];
    }
  }

  printf("%d\n",maxv);

  return 0;
}
