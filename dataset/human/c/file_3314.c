#include<stdio.h>

int main(void){
int k,n,i,dif,diff;
  int sum=0;
  scanf("%d", &k);
  scanf("%d", &n);
  int a[n];
  for(i=0;i<n;i++){
  scanf("%d", &a[i]);
  }
  dif=a[1]-a[0];
  for(i=1;i<n-1;i++){
    diff=a[i+1]-a[i];
    if(dif<diff){
    dif=diff;
    }
  }
  diff=(k-a[n-1])+(a[0]);
  if(dif<diff){
  dif=diff;
  }
  sum=k-dif;
  printf("%d\n", sum);
  return 0;
}
