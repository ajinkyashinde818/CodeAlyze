#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

const int64_t R = 1e9 + 7;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

bool isL[200'000];

int main()
{
    int64_t n;
    string s;
    cin >> n >> s;

    rep(i, 2 * n)
    {
        int flip = i + (s[i] == 'B' ? 1 : 0);
        isL[i] = (flip % 2 == 1);
    }

    int64_t lnum = 0;
    int64_t rnum = 0;
    int64_t cmb = 1;
    rep(i, 2 * n)
    {
        if (isL[i]) {
            lnum++;
        } else {
            cmb = cmb * (lnum - rnum) % R;
            rnum++;
        }
    }

    if (s[0] == 'W' || s[2 * n - 1] == 'W' || lnum != rnum) {
        cout << 0 << endl;
        return 0;
    }

    rep(i, n)
    {
        cmb = cmb * (i + 1) % R;
    }
    cout << cmb << endl;

    return 0;
}
