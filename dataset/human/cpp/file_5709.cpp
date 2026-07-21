#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

using int64 = long long;

const int MAX_N = 200000;

int N;
int64 L;

int64 result = 0;

string s[MAX_N];
vector<int64> heights;

int64 calc_grundy(int64 x) {
    if (x == 0) return 0;

    int64 res = 1;
    while (x % 2 == 0) {
        x /= 2;
        res *= 2;
    }
    return res;
}

string prefix = "";

void dfs(int64 dep, int lb, int ub) {
    int num = ub - lb;
    if (num == 0) {
        result ^= calc_grundy(L + 1 - dep);
        return;
    } else if (num == 1) {
        int64 h = L - dep + 1;
        int64 sh = L - s[lb].size() + 1;

        for (int64 x = sh; x < h; x++) {
            result ^= calc_grundy(x);
        }
        return;
    }

    prefix.push_back('1');
    int b = lower_bound(s + lb, s + ub, prefix) - s;
    prefix.pop_back();

    prefix.push_back('0');
    dfs(dep + 1, lb, b);
    prefix.pop_back();

    prefix.push_back('1');
    dfs(dep + 1, b, ub);
    prefix.pop_back();
}

int main() {
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    sort(s, s + N);

    dfs(0, 0, N);

    if (result) cout << "Alice" << endl;
    else cout << "Bob" << endl;

    return 0;
}
