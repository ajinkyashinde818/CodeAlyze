#include<stdio.h>
int main(void){
int n,k;
  scanf("%d%d",&n,&k);
  int a[n],sum=0;
  for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
    if(a[i]>=k)sum++;
  }
  printf("%d",sum);
  return 0;
}
