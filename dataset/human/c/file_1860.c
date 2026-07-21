#include <stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  int a[n],b[n],c[n-1];
  for(int i=0;i<n;i++){
    scanf("%d ",&a[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d ",&b[i]);
  }
  for(int i=0;i<n-1;i++){
    scanf("%d ",&c[i]);
  }
  int ans=b[a[0]-1];
  for(int i=1;i<n;i++){
    ans+=b[a[i]-1];
    if(a[i]==a[i-1]+1){
      ans+=c[a[i-1]-1];
    }
  }
  printf("%d\n",ans);
  return 0;
}
