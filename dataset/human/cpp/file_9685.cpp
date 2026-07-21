#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

using namespace std;

template <typename T> void output(T, int);
int gcd(int a, int b);

int main() {
    // source
    int n, m;
    cin >> n >> m;
    string a[n];
    rep(i, n) { cin >> a[i]; }

    string b[m];
    rep(i, m) { cin >> b[i]; }

    rep(l0, n - m + 1) {
        rep(l1, n - m + 1) {
            bool temp = true;
            rep(m1, m) {
                rep(m2, m) {
                    if (a[m1 + l0][m2 + l1] != b[m1][m2]) {
                        temp = false;
                    }
                }
            }

            if (temp) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}

template <typename T> void output(T a, int precision) {
    if (precision > 0) {
        cout << setprecision(precision) << a << "\n";
    } else {
        cout << a << "\n";
    }
}

template <typename T> T min(T a, T b) {

    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
