#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;

typedef long long ll;

long long GCD(long long a, long long b){if(b==0)return a;return GCD(b,a%b);}

int main() {
    int R, G, B, N; cin >> R >> G >> B >> N;
    int res = 0;
    
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            int tmp = N - i*R - j*G;
            int k = tmp / B;
            if (tmp % B == 0 && k >= 0) ++res;
        }
    }
    cout << res << endl;

}
