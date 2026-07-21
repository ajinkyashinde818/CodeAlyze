#include <stdio.h>
#define N 200000
#define MIN -1000000000
int main(){

  int i, j, n, r[N], max=MIN, min, prof;

  scanf("%d",&n);

  scanf("%d",&r[0]);
  
  min = r[0];
  
  for(i=1;i<n;i++){
    scanf("%d",&r[i]);
    prof=r[i]-min;
    if(i==1||max<prof)max=prof;
    if(min>r[i])min=r[i];
  }
  printf("%d\n",max);
  
  return 0;
}
