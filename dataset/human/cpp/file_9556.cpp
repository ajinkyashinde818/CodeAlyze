#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>


using std::cout;
using std::cin;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) {
    while (b != 0) {
        auto tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int isPrime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}




void oneCase () {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for (auto& l : a) {
        cin >> l;
    }
    for (auto& l : b) {
        cin >> l;
    }
    for (int row = 0; row + m <= n; ++row) {
        for (int col = 0; col + m <= n; ++col) {
            bool contain = true;
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < m; ++c) {
                    if (a[row + r][col + c] != b[r][c]) {
                        contain = false;
                        break;
                    }
                }
                if (!contain) {
                    break;
                }

            }
            if (contain) {
                cout << "Yes" << "\n";
                return;
            }
        }
    }
    cout << "No" << "\n";


}





int main() {
    int t = 1;
//    cin >> t;
    while (t > 0) {
        oneCase();
        --t;
    }

    return 0;
}
