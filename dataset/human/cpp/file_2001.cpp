#include <iostream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cmath>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> p_i;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repext(i, a, b) for (int i = a; i < b; i++)
#define reprev(i, n) for (int i = n - 1; i >= 0; i--)
#define repextrev(i, a, b) for (int i = b - 1; i >= a; i--)

#define repv(v, values) for (auto v : values)

#define vec_all(vec) vec.begin(), vec.end()
#define sum(vec) accumulate(vec_all(vec), 0LL)
#define srt(vec) sort(vec_all(vec))
#define rev(vec) reverse(vec_all(vec))
#define revsrt(vec) \
    srt(vec);       \
    rev(vec)

// vectorデバッグ
template <typename T>
void dump_vec(vector<T> vec)
{
    rep(i, vec.size())
    {
        cout << i << ": " << vec[i] << endl;
    }
}

template <typename T, typename S>
void dump_dic(map<T, S> dic)
{
    for (auto v : dic)
    {
        cout << v.first << ": " << v.second << endl;
    }
}

// --- notice ---
// intの和はllにしろ

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int min = 1000000001;
    int mindex;
    int tmp;
    rep(i, n) {
        cin >> a[i];
        tmp = abs(a[i]);
        if (tmp < min) {
            mindex = i;
            min = tmp;
        }
    }

    rep(i, mindex) {
        if (a[i] < 0) {
            a[i] = -a[i];
            a[i + 1] = -a[i + 1];
        }
    }

    repextrev(i, mindex + 1, n) {
        if (a[i] < 0) {
            a[i] = -a[i];
            a[i - 1] = -a[i - 1];
        }
    }

    cout << sum(a) << endl;
    return 0;
}
