#include<stdio.h>

int main(){
  int n = 0;
  int k = 0;
  int h[100000] = {};
  int i = 0;
  int cnt = 0;
  scanf("%d",&n);
  scanf("%d",&k);
  for(i = 0;i < n;i++){
    scanf("%d",&h[i]);
  }
  for(i = 0;i < n;i++){
    if(h[i] >= k){
      cnt++;
    }
  }
  printf("%d",cnt);
  return 0;
}
