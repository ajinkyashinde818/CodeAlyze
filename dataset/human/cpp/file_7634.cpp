#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <utility>
using namespace std;

void solve(long long N, std::vector<long long> a){
    auto l=a[0];
    auto r=accumulate(a.begin()+1, a.end(), 0l);
    auto ans = abs(l-r);
    for(int i=1; i<N-1; i++){
        l+=a[i];
        r-=a[i];
        ans = min(ans, abs(l-r));
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
