#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <tuple>
#include <utility>
#include <limits>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <cassert>

using namespace std;

template<typename T, size_t N>
constexpr size_t NELEMS(T (&)[N]) { return N; }

template<typename InputIt>
void PRINT_RANGE(InputIt first, InputIt last)
{
    for(; first != last; ++first)
        cout << *first << (first==last ? "" : " ");
    cout << "\n";
}

#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

#define DEBUG
#undef DEBUG

using ll  = long long;
using ull = unsigned long long;

int N, M;
char A[50][50];
char B[50][50];

bool match(int i, int j)
{
    FOR(k, 0, M) {
        FOR(l, 0, M) {
            if(B[k][l] != A[i+k][j+l])
                return false;
        }
    }

    return true;
}

void solve()
{
    FOR(i, 0, N-M+1) {
        FOR(j, 0, N-M+1) {
            if(match(i, j)) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int main()
{
    cin >> N >> M;
    REP(i, N) {
        string s;
        cin >> s;
        REP(j, N) {
            A[i][j] = s[j];
        }
    }
    REP(i, M) {
        string s;
        cin >> s;
        REP(j, M) {
            B[i][j] = s[j];
        }
    }

    solve();

    return 0;
}
