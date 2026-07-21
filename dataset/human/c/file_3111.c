#include<stdio.h>
int main(void){
  int k,n;
  scanf("%d%d",&k,&n);
  int a[n];
  for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
  }
int d[n],max=0;
  for(int i=0;i<n-1;i++){
	d[i]=a[i+1]-a[i];
    if(d[i]>max)max=d[i];
  }
  d[n-1]=a[0]+k-a[n-1];
  if(d[n-1]>max)max=d[n-1];
  printf("%d",k-max);
  return 0;
}
