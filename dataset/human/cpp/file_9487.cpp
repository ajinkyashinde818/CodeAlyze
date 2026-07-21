#include <iostream>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;
typedef long long int ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
ll MOD = 1000000007;
#define INF (1e9)

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
typedef pair <ll,ll> P;

int main()
{
    ll M, N;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    bool flag = false;
    rep(i, N - M+1) {
        rep(j, N-M+1) {
            flag = false;
            rep(s, M) {
                rep(t, M) {
                    if (A[i+s][j+t] != B[s][t]) flag = true;
                }
            }
            if (!flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
