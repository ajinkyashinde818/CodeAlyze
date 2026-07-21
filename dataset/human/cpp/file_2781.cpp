//負数が偶数個：全部正数にできる
//負数が奇数個：全部正数にする（ただしこのときは一つの正数を負数にする必要がある）
//あるいは負数を1つそのままにしとく
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
    long long N,nega=0,negamax=-mod,posimin=mod;
    long long ans=0;
    cin >> N;
    vector<long long>A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A.at(i);
        ans += abs(A.at(i));
        if (A.at(i) >= 0)posimin = min(A.at(i), posimin);
        else {
            negamax = max(negamax, A.at(i));
            nega++;
        }
    }
    if(nega%2)ans -= min(-negamax, posimin) * 2;
    cout << ans;
}
