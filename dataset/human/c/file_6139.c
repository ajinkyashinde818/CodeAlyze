#include <stdio.h>
#define N 200000
int main(){
  int n,i,ans,min;
  int A[N+1];
  scanf("%d",&n);
  for(i=1;i<=n;i++) scanf("%d",&A[i]);
  min=A[1];
  ans=A[2]-A[1];
  for(i=2;i<=n;i++){
    if(A[i]-min>ans) ans=A[i]-min;
    if(min>A[i]) min=A[i];
  }
  printf("%d\n",ans);
  return 0;
}
