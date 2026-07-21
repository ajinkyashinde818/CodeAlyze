#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    int N;
    long long C;
    cin >> N >> C;
    vector<long long> x(N+1, 0), v(N+1, 0);
    for(int i=1; i<=N; i++) cin >> x[i] >> v[i];

    vector<long long> a0(N+2, 0), a1(N+2, 0), a3(N+2, 0), a4(N+2, 0);
    vector<long long> b0(N+2, 0), b1(N+2, 0);

    for(int i=1; i<=N; i++)
        b0[i] = b0[i-1] + v[i];
    for(int i=N; i>=1; i--)
        b1[i] = b1[i+1] + v[i];

    for(int i=1; i<=N; i++)
        a0[i] = b0[i] - x[i];
    for(int i=N; i>=1; i--)
        a1[i] = b1[i] - (C - x[i]);

    vector<long long> aa0(N+2, 0), aa1(N+2, 0);
    for(int i=1; i<=N; i++)
        a4[i] = b0[i] - 2*x[i];

    for(int i=N; i>=1; i--)
        a3[i] = b1[i] - 2*(C-x[i]);

    long long ans = 0;

    vector<long long> c0 = a0, c1 = a1, c3 = a3, c4 = a4;
    for(int i=1; i<=N; i++) c0[i] = max(c0[i], c0[i-1]);
    for(int i=1; i<=N; i++) c4[i] = max(c4[i], c4[i-1]);
    for(int i=N; i>=1; i--) c1[i] = max(c1[i], c1[i+1]);
    for(int i=N; i>=1; i--) c3[i] = max(c3[i], c3[i+1]);
    for(int i=1; i<=N; i++)
        ans = max(ans, c0[i] + c3[i+1]);
    for(int i=1; i<=N; i++)
        ans = max(ans, c4[i] + c1[i+1]);

    sort(a0.begin(), a0.end());
    sort(a1.begin(), a1.end());
    ans = max(ans, a0.back());
    ans = max(ans, a1.back());

    cout << ans << endl;

    return 0;
}
