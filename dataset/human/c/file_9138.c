#include<stdio.h>
int main(void){
  int n,k,i,cnt=0;
  scanf("%d %d",&n,&k);
  int num[n];
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
    if(num[i]>=k){
      cnt++;
    }
  }
  printf("%d",cnt);
  return 0;
}
