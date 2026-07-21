#include <stdio.h>
int main(){
  int n,d,x,a[100],i,sum=0;
  scanf("%d%d%d",&n,&d,&x);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    sum+=d/a[i]+(d%a[i]!=0);
  }
  printf("%d",sum+x);
}
