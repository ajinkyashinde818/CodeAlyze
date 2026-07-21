#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4, MOD = (int)1e9+7;
int N; char s[NS];
int cnt[30];

int main(){
    int ans = 1;
    scanf("%d %s", &N, &s);
    for(int i=0;i<N;++i) ++cnt[s[i]-'a'];
    for(int i=0;i<26;++i) ans = (long long)ans*(cnt[i]+1)%MOD;
    printf("%d\n", ans-1);
    return 0;
}
