#include <stdio.h>
int main(void)
{
  int k,n,i;
  int b,c;
  int d=0;
  int a[200000];
  scanf("%d",&k);
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i<n;i++){
    if(i==n-1){
      b=k-a[n-1]+a[0];
    }
    else{
      b=a[i+1]-a[i];
    }
    c+=b;
      if(b>d)
        d=b;
  }
  printf("%d",c-d);
  return 0;
}
