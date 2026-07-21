#include <stdio.h>
int main()
{
  int n,i,j,min,max;
  int array[200000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }

  min=array[0];
  max=array[1]-array[0];
  for(j=1;j<n;j++){
    if(max<array[j]-min){
      max=array[j]-min;
    }
    if(min>array[j]){
      min=array[j];
    }
  }

  printf("%d\n",max);
  return 0;
}
