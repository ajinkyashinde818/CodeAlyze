#include<bits/stdc++.h>
using namespace std;

int main(){
    int_fast64_t N, C;
    scanf("%lld%lld", &N, &C);
    vector<pair<int_fast64_t, int_fast64_t>> cw(N + 1), ucw(N + 1);
    vector<pair<int_fast64_t, int_fast64_t>> sushi(N + 1);
    for(uint_fast64_t i = 0; i < N; ++i)scanf("%lld%lld", &sushi[i].first, &sushi[i].second);
    cw[0] = make_pair(0, 0);
    cw[1] = make_pair(sushi[0].second - sushi[0].first, sushi[0].first);
    for(uint_fast64_t i = 2; i <= N; ++i){
        cw[i] = make_pair(cw[i - 1].first + sushi[i - 1].second + sushi[i - 2].first - sushi[i - 1].first, sushi[i - 1].first);
    }
    ucw[0] = make_pair(0, 0);
    ucw[1] = make_pair(sushi[N - 1].second - C + sushi[N - 1].first, C - sushi[N - 1].first);
    for(uint_fast64_t i = 2; i <= N; ++i){
        ucw[i] = make_pair(ucw[i - 1].first + sushi[N - i].second + sushi[N - i].first - sushi[N - i + 1].first, C - sushi[N - i].first);
    }
    partial_sum(cw.begin(), cw.end(), cw.begin(), [](pair<int_fast64_t, int_fast64_t> a, pair<int_fast64_t, int_fast64_t> b){return max(a, b);});
    partial_sum(ucw.begin(), ucw.end(), ucw.begin(), [](pair<int_fast64_t, int_fast64_t> a, pair<int_fast64_t, int_fast64_t> b){return max(a, b);});
    int_fast64_t ans(numeric_limits<int_fast64_t>::min());
    for(uint_fast64_t i = 0; i <= N; ++i){
        ans = max({ans, cw[i].first, ucw[N - i].first, cw[i].first + ucw[N - i].first - min(cw[i].second, ucw[N - i].second)});
    }
    printf("%lld\n", ans);
    return 0;
}
