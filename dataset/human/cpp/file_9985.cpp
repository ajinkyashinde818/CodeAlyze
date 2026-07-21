#include<bits/stdc++.h>
using namespace std;

const int maxn=100003;
const int mo=1000000007;

int n,cnt[31],res=1;
char s[maxn];

int main(){
  scanf("%d",&n);
  scanf("%s",s+1);
  for(int i=1;i<=n;++i)
    ++cnt[s[i]-'a'];
  for(int i=0;i<26;++i)if(cnt[i]){
    res=(1ll*res*(cnt[i]+1))%mo;
  }
  printf("%d\n",(res+mo-1)%mo);
  return 0;
}
