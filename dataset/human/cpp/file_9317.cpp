#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, a, n) for (int i = a; i < (n); i++)
#define all(in) in.begin(), in.end()
const int INF = 1e9;
const int MOD = 1e9 + 7;
int main() {
    int N, M;
    cin >> N >> M;
    string A[N], B[M];
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    bool exist = false;
    rep(iy, N) {
        rep(ix, N) {
            if (ix + M - 1 >= N || iy + M - 1 >= N) continue;
            bool match = true;
            rep(ky, M) {
                rep(kx, M) {
                    if (A[ky + iy][kx + ix] != B[kx][ky]) match = false;
                }
            }
            if (match) exist = true;
        }
    }
    if (exist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
