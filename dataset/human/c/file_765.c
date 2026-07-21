#include<stdio.h>

int main(void){
  char S[100001];
  int n;
  long long int ans = 1,mod = 1000000007,c[26] = {0};
  
  scanf("%d",&n);
  scanf("%s",S);
  
  for(int i = 0;i<n;i++){
    c[S[i] - 'a']++;
  }
  
  for(int i = 0;i<26;i++){
    ans = ans * (c[i] + 1) % mod;
  }
  printf("%lld",ans - 1);
}
