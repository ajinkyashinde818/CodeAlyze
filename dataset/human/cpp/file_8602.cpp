#include <iostream>
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
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

#define DEBUG

#ifdef DEBUG
#define var_dump(...) fprintf(stdout, __VA_ARGS__)
#define dump(a) cout << a << "\n";
#else
#define var_dump(...) 42
#define dump(a) 42
#endif

// https://beta.atcoder.jp/contests/abc054/tasks/abc054_b

int main() {
    int N, M; cin >> N >> M;
    string A[N];
    string B[M];

    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    REP(i, N-M+1) {
        REP(j, N+M+1) {

            bool match = true;
            REP(k, M) {
                REP(l, M) {
                    if (B[k][l] != A[k+i][l+j]) {
                        match = false;
                    }
                }
            }

            if (match) {
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }

    cout << "No" << "\n";
    return 0;
}
