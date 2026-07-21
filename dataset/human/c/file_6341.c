#include <stdio.h>
int main(void)
{
  int n;
  scanf("%d",&n);
  int R[n];
  int i;
  for(i=0;i<n;i++) {
    scanf("%d",&R[i]);
  }
  int max=R[1]-R[0];
  int min=R[0];
  for(i=1;i<n;i++) {
    if(R[i]-min>max)
      max=R[i]-min;
    if(R[i]<min)
      min=R[i];
  }
  printf("%d\n",max);
  return 0;
}
