// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

int N, M;
char A[50][55], B[50][55];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    bool ok = false;
    for (int sx = 0; sx < N-M+1; ++sx) {
        for (int sy = 0; sy < N-M+1; ++sy) {
            bool identical = true;
            for (int x = 0; x < M; ++x) {
                for (int y = 0; y < M; ++y) {
                    if (A[sx+x][sy+y] != B[x][y]) {
                        identical = false;
                    }
                }
            }
            if (identical) ok = true;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
