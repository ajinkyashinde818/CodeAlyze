#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5, mod = 1e9+7;
int N, i, cnt[30], ans=1;
char ch;

int main(){
    scanf("%d",&N); getchar();
    for(i=1;i<=N;i++){
        scanf("%c",&ch);
        cnt[ch-'a']++;
    }
    for(i=0;i<26;i++){
        ans = (1LL*ans*(cnt[i]+1))%mod;
    }
    ans = (ans-1+mod)%mod;
    printf("%d\n",ans);
    return 0;
}
