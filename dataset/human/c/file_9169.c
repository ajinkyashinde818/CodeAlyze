#include<stdio.h>
int main(){
  int n,k,h[100001],i,cnt=0;
  scanf("%d%d",&n,&k);
  for(i=0; i<n; i++){
    scanf("%d",&h[i]);
    if(h[i]>=k){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;

}
