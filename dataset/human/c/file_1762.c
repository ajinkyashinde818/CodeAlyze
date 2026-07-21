#include "stdio.h"

int main(){
  //代入
  int n,a[21],b[21],c[21],ans=0;
  scanf("%d ",&n);
  for(int i=0;i<n;i++){scanf("%d ",&a[i]);}
  for(int i=0;i<n;i++)scanf("%d ",&b[i]);
  for(int i=0;i<n-1;i++)scanf("%d ",&c[i]);
  c[n-1]=0;
 
  for(int i=0;i<n;i++){
    ans+=b[a[i]-1];
    if(i!=0&&a[i]==a[i-1]+1)ans+=c[a[i-1]-1];
  }

  
  printf("%d",ans);
  return 0;
}
