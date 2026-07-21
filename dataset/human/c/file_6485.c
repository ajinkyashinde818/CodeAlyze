#include<stdio.h>
#define N 200000

int main(){
  int i,j,max,min,n,k;
  int a[N];
  
  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }
  min = a[0];
  max =a[1]-a[0];
  for(j=1; j<n; j++){
    k=a[j]-min;
      if(max < k)max = k;
      if(min > a[j])min=a[j];
  }
  printf("%d\n",max);
  return 0;
}
