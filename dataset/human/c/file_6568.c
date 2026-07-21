#include<stdio.h>
#define N 200000

int main()
{
  int i, n, max, min;
  int R[N];
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d",&R[i]);
  }

  min=R[0];
  max=R[1]-R[0];
  for(i = 1; i < n; i++){
    if(max < R[i]-min) max=R[i]-min;
    if(R[i] < min) min=R[i];
  }
  
  printf("%d\n", max);
  return 0;
}
