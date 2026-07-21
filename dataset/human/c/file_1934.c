#include <stdio.h>

int main(){
  int n;
  int ans=0;
  scanf("%d",&n);
  
  int a[n+1],b[n+1],c[n];
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&b[i]);
    ans=ans+b[i];
  }
  for(int i=1;i<n;i++){
    scanf("%d",&c[i]);
  }
  
  for(int i=1;i<n;i++){
    if(a[i+1]-a[i]==1){
      ans=ans+c[a[i]];
    }
  }
  
  printf("%d",ans);
  
  return 0;
}
