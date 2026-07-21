#include <stdio.h>
int main(void){
  int n,b,ans=0;
  scanf("%d",&n);
  int a[n],c[n-1];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&b);
    ans=ans+b;
  }
  for(int i=0;i<n-1;i++){
    scanf("%d",&c[i]);
  }
  for(int i=0;i<n-1;i++){
    if(a[i]+1==a[i+1]){
      ans=ans+c[a[i]-1];
    }
  }
  printf("%d",ans);
}
