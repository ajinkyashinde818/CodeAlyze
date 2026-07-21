#include<stdio.h>

int main(void){
  int n,i,temp,res=0,a[21]={},b[21]={},c[21]={};
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  for(i=0;i<n;i++) scanf("%d",&b[i]);
  for(i=0;i<n-1;i++) scanf("%d",&c[i]);
  for(i=0;i<n;i++){
    res += b[a[i]-1];
    if(a[i]+1==a[i+1]) res += c[a[i]-1];
  }
  printf("%d\n",res);
  return 0;
}
