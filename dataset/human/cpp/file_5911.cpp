// ※※※ 解答不能 ※※※
// 以下のソースを勉強する.
// ひふみ☆氏.
// https://arc096.contest.atcoder.jp/submissions/2391737
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

template<typename A,typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A,typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const LL INF=1001001001001001001ll;
int N;
LL C, ans;
LL X[555555], V[555555];
LL S[555555];

void solve(){
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + V[i];
    LL ma = -INF;
    for(int i = N - 1; i >= 0; i--){
        chmax(ans, S[i + 1] - X[i]);
        chmax(ans, S[i + 1] - 2 * X[i] + ma - C);
        chmax(ma, S[N] - S[i] + X[i]);
    }
}

signed main(){
    
    scanf("%d %lld", &N, &C);
    vector<LL> x(N), v(N);
    for(int i = 0; i < N; i++) scanf("%lld %lld", &x[i], &v[i]);
    for(int t = 0; t < 2; t++){
        for(int i = 0; i < N; i++) X[i] = x[i], V[i] = v[i];
        solve();
        for(int i = 0; i < N; i++) x[i] = C - x[i];
        reverse(x.begin(), x.end());
        reverse(v.begin(), v.end());
    }
    printf("%lld\n", ans);
    return 0;
}
