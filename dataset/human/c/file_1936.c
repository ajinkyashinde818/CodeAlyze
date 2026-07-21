#include <stdio.h>

int main(){
  int n;if(scanf("%d",&n)==1){}
  int a[n],b[n],c[n-1];int i;
  for(i=0;i<n;i++){
    if(scanf("%d",&a[i])==1){}
  }
  for(i=0;i<n;i++){
    if(scanf("%d",&b[i])==1){}
  }
  for(i=0;i<n-1;i++){
    if(scanf("%d",&c[i])==1){}
  }
  long int sum=b[a[0]-1];
  for(i=1;i<n;i++){
    sum+=b[a[i]-1];
    if((a[i]-a[i-1])==1)sum+=c[a[i-1]-1];
  }
  printf("%d",sum);
  return 0;
}
