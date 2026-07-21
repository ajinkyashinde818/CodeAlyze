#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <unordered_map>
#define Debug 0
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 998244353;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % MOD;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}

//最大公約数
template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

//最小公倍数
template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

//入出力高速化(非同期化)
void fast_input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main(void) {
    int N; cin >> N;
    vector<int> a(N);
    int cnt = 0;
    long long sum = 0;
    int mi = 1000000001;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        mi = min(abs(a[i]), mi);
        sum += abs(a[i]);
    }
    for (int i = 0; i < N; i++) {
        if (a[i] < 0) cnt++;
        if (a[i] == 0) {
            cnt = 0;
            break;
        }
    }
    if (cnt % 2) {
        cout << sum-mi*2 << endl;
    } else {
        cout << sum << endl;
    }

}
