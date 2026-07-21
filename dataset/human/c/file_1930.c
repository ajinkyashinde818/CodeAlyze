#include<stdio.h>
int main(){
  int n,a[100],b[100],c[100],s=0,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  for(i=0;i<n;i++)scanf("%d",&b[i]);
  for(i=1;i<n;i++)scanf("%d",&c[i]);
  for(i=0;i<n;i++){
    s+=b[a[i]-1];//printf("%d ",s);
    if(i&&a[i-1]+1==a[i])s+=c[a[i-1]];//printf("%d\n",s);
  }
  printf("%d\n",s);
  return 0;
}
