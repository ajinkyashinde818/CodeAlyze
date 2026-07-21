#include<stdio.h>
int main()
{
  int n , R[200005];
  int R_max, R_min;
  int i;

  scanf("%d", &n);

  for(i=0; i<n; i++){

  scanf("%d", &R[i]);

  if(i==0){
  R_min=R[i];
  continue;
}

  if(i==1) R_max = R[1]-R[0];

  if(R_max <= (R[i]-R_min)) R_max = R[i]-R_min;
  if(R_min >= R[i]) R_min = R[i];
}

  printf("%d\n", R_max);

  return 0;
}
