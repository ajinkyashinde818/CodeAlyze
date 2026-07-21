#include<stdio.h>
#define N 200000

int main()
{
  int n,i;
  int R[N];
  int Min,Max;
  
  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&R[i]);
  }

  Min = R[0];
  Max = R[1]-R[0];

  for(i=1; i<n; i++){
    if((R[i]-Min) > Max)
      Max = R[i]-Min;
    if(Min > R[i])
      Min = R[i];
  }

  printf("%d\n",Max);
  return 0;
}
