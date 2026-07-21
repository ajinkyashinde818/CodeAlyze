#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

vector< u64 > A = vector< u64 >(50, 0);
vector< u64 > B = vector< u64 >(50, 0);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    string s;
    rep (i, N)
    {
        cin >> s;
        rep (j, N)
        {
            A[i] = (A[i] << 1) + (s[j] == '.' ? 0 : 1);
        }
    }
    rep (i, M)
    {
        cin >> s;
        rep (j, M)
        {
            B[i] = (B[i] << 1) + (s[j] == '.' ? 0 : 1);
        }
    }
    u64 mask = 0;
    rep (i, M) mask = (mask << 1) + 1;

    bool ans = false;
    for (int i = 0; i < N - M + 1 && !ans; ++i)
    {
        for (int j = 0; j < N - M + 1 && !ans; ++j)
        {
            int temp = 0;
            rep (ii, M)
            {
                temp |= ((A[i + ii] >> (N - M - j)) & mask) ^ B[ii];
            }
            if (temp == 0) ans = true;
        }
    }

    if (ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
