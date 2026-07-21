#include <stdio.h>
#include <stdlib.h>

#define max(x,y)  (x > y) ? x:y
#define min(x,y)  (x < y) ? x:y

int main(){
  int n;
  int maxv,minv;
  int i;
  int *R;

  scanf("%d",&n);
  R = (int *)malloc(sizeof(int) * n);

  for (i = 0;i < n;i++)
    scanf("%d",&R[i]);

  maxv = R[1] - R[0];
  minv = R[0];

  for (i = 1;i < n;i++){
    maxv = max(maxv,R[i] - minv);
    minv = min(minv,R[i]);
  }

  printf("%d\n",maxv);
  free(R);
  
  return 0;
}
