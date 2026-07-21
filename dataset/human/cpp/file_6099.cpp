#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL x[maxn], v[maxn];
multiset<LL> MS;
multiset<LL> :: iterator it;

int main(){
    int N;
    LL C;
    scanf("%d %lld", &N, &C);
    LL tmp = 0, tmp2 = 0, M = 0;
    for(int i = 1; i <= N; ++i) scanf("%lld %lld", x + i, v + i);
    for(int i = 1; i <= N; ++i){
        tmp += v[i];
        M = max(M, tmp - x[i]);
        MS.insert(tmp - x[i]);
    }
    for(int i = N; i >= 1; --i){
        it = MS.find(tmp - x[i]);
        MS.erase(it);
        if(MS.empty()) break;
        tmp -= v[i];
        tmp2 += v[i];
        LL MM = *MS.rbegin();
        M = max(M, MM + tmp2 - 2 * (C - x[i]));
    }

    for(int i = 1; i <= N / 2; ++i) swap(x[i], x[N-i+1]), swap(v[i], v[N-i+1]);
    for(int i = 1; i <= N; ++i) x[i] = C - x[i];

    MS.clear();
    tmp = 0, tmp2 = 0;
    for(int i = 1; i <= N; ++i){
        tmp += v[i];
        M = max(M, tmp - x[i]);
        MS.insert(tmp - x[i]);
    }
    for(int i = N; i >= 1; --i){
        it = MS.find(tmp - x[i]);
        MS.erase(it);
        if(MS.empty()) break;
        tmp -= v[i];
        tmp2 += v[i];
        LL MM = *MS.rbegin();
        M = max(M, MM + tmp2 - 2 * (C - x[i]));
    }
    printf("%lld\n", M);
    return 0;
}
