#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void){
  int n,k;
  scanf("%d%d",&k,&n);
  int a[n],sum1=0,max=0,sum,i,sum2;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<n;i++){
    sum1+=(a[i]-a[i-1]);
  }
  sum2=sum1;
  for(i=1;i<n;i++){
    if(max<a[i]-a[i-1]) max=a[i]-a[i-1];
  }
  sum=sum1-max+(k-a[n-1]+a[0]);
  printf("%d",sum2<sum?sum2:sum);
    return 0;
}
