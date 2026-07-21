#include<stdio.h>
#include<math.h>

#define MAX 200000

int main(){

  int R[MAX], n, i=0;
  int maxv=-2000000000, minv=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&R[i]);
  }

  minv = R[0];

  for(i=1; i<n; i++){
    maxv = fmax(maxv,R[i]-minv);
    minv = fmin(minv,R[i]);
  }

  printf("%d\n",maxv);

  return 0;
}
