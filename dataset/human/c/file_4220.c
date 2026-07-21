#include <stdio.h>

int main(){
  int n,m;
  int mod = 1000000007;
  scanf("%d%d\n",&n,&m);
  int num[n+1],broken[m];
  for(int i = 0; i < m; ++i) scanf("%d\n",&broken[i]);
  int flag = 0;
  for(int i = 0; i < n+1; ++i) num[i] = 0;
  for(int i = 0; i < m-1; ++i){
    if(broken[i+1] - broken[i] < 2){
      flag = 1;
      num[n] = 0;
    }
    num[broken[i]] = -1;
  }
  if(m > 0) num[broken[m-1]] = -1;
  num[0] = 1;
  if(flag == 0){
    for(int i = 1; i < n+1; ++i){
      if(num[i] != -1){
        if(i == 1) num[i] = num[0];
        else{
          if(num[i-1] != -1) num[i] = (num[i] + num[i-1]) % mod;
          if(num[i-2] != -1) num[i] = (num[i] + num[i-2]) % mod;
        }
      }
    }
  }
  printf("%d",num[n]);
  return 0;
}
