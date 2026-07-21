#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <random>
#include <string>
#include <bitset>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define FORR(i, m, n) for(int i = m; i >= n; --i)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define INF 999999999

using namespace std;

typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};

llong pow(int x, int n) {
    llong ans = x;
    if (n == 0) return 1;

    for(int i = 0; i < n - 1; i++) {
        ans *= x;
    }

    return ans;
}

void swap(int *X, int *Y){
    int t = *X; *X = *Y; *Y = t;
}

const static int MAX = 50;
int main() {
    int n, m;
    cin >> n >> m;
    char tmp1, tmp2;
    if (n == 1 && m == 1) {
        cin >> tmp1 >> tmp2;
        cout << ((tmp1 == tmp2) ? "Yes" : "No") << endl;
        return 0;
    }
    char N[MAX][MAX];
    char M[MAX][MAX];
    string in;
    REP(i, n) {
        cin >> in;
        REP(j, in.size()) {
            N[i][j] = in[j];
        }
    }
    REP(i, m) {
        cin >> in;
        REP(j, in.size()) {
            M[i][j] = in[j];
        }
    }

    bool flag_1 = false, flag_2 = false;
    int cnt = 0;
    REP(i, n) {
        REP(j, n) {
            if (N[i][j] == M[0][0] && (n - j) >= m && (n - i) >= m) {
                for (int k = 0; k < m; ++k) {
                    for (int l = 0; l < m; ++l) {
                        if (N[i + k][j + l] == M[k][l]) {
                            cnt += 1;
                        } else {
                            flag_1 = true;
                            cnt = 0;
                            break;
                        }
                    }
                    if (flag_1) break;
                }
            }
            flag_1 = false;
            if (cnt == m * m) {
                flag_2 = true;
                break;
            }
        }
        if (flag_2) break;
    }

    if (flag_2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
