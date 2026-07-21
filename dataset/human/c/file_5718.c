#include<stdio.h>
#include<limits.h>

int main(){
  int i,n,mx=INT_MIN,mn=INT_MAX;
  scanf("%d",&n);
  int h[n];
  for(i=0;i<n;i++){
    scanf("%d",&h[i]);
    if(i==0){
      mn=h[i];
      continue;
    }
    if(h[i]-mn>mx)mx=h[i]-mn;
    if(mn>h[i])mn=h[i];
    //printf("%d%d\n",mx,mn);
    
  }
  printf("%d\n",mx);
  return 0;
}
