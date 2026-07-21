#include <stdio.h>
int main(void){
  int n,a[100000],r[100000]={},t=0,i,ans=0;
  bool k=true;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
    a[i]--;
  }
  r[0]=1;
  while (1){
    ans++;
    t=a[t];
    if (t==1) break;
    if (r[t]){
      k=false;
      break;
    }
    r[t]=1;
  }
  printf("%d\n",(k)? ans:-1);
  return 0;
}
