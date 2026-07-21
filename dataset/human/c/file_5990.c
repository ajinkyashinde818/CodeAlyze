#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n,i,max,min;
  int *R;
  scanf("%d",&n);
  R=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    scanf("%d",&R[i]);

  max=-2000000000;
  min=R[0];

  for(i=1;i<n;i++){
    if(max<R[i]-min)max=R[i]-min;
    if(min>R[i])min=R[i];
  }
  
  printf("%d\n",max);
  return 0;
}
