#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  char s[n+1];
  scanf("%s",s);
  long long int ans = 1;
  int num[26];
  int i;
  for(i=0;i<26;i++){
    num[i] = 0;
  }
  for(i=0;i<n;i++){
    num[(s[i]-'a')]++;
  }
  for(i=0;i<26;i++){
    ans = (ans * (num[i]+1)) % 1000000007;
  }
  ans--;
  printf("%lld\n", ans);
  return 0;
}
