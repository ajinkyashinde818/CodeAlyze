#include <stdio.h>
int main(){
  int n,i,a[100001],t=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  for(i=0;i<n+1;i++){
    t=a[t]-1;
    if(t==1){
      printf("%d",i+1);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
