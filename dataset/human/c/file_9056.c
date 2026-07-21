#include <stdio.h>

int main(void){
  int n,k;
  
  scanf("%d %d",&n,&k);
  
  int ans=0;
  int a[n];
  
  for(int i =0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]>=k){ans++;}
  }
  
  printf("%d\n",ans);
  
  return 0;
}
