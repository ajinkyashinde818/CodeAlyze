#include <stdio.h>
int main(void){
  char s[100010];
  int n;
  scanf("%d %s",&n,s);
  long long int i,cnt[100]={0},sum=1;
  for(i=0;i<n;i++) {
    int num=s[i]-'a';
    cnt[num]++;
  }
  for(i=0;i<26;i++) sum=(sum*(cnt[i]+1))%1000000007;
  printf("%lld\n",sum-1);
  return 0;
}
