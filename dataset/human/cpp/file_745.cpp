#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<P ,ll> P3;
typedef pair<P ,P> PP;
const ll MOD = ll(1e9)+7;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-6;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

int main() {
    int R, G, B, N, ans = 0;
    cin >> R >> G >> B >> N;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(N-i*R-j*G >= 0 && (N-i*R-j*G) % B == 0) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
