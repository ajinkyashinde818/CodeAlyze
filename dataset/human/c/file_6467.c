#include<stdio.h>
int main(){
  int n;
  int a;
  int mn=1000000000;
  int i,ans=-1000000000;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    if(i==0 && mn>a) mn=a;
    if(i>0 && ans<a-mn) ans=a-mn;
    if(i!=0 && mn>a) mn=a;
  }
  printf("%d\n",ans);
  return 0;
}
