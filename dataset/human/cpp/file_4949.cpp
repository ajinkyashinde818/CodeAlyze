#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <complex>
#include <algorithm>

using namespace std;
using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using i32 = int_fast32_t;
using u32 = uint_fast32_t;

#define int i64

template<class T>
inline bool chmin(T &a, T b) { if(a > b) {a = b; return true;} return false; }
template <class T>
inline bool chmax(T &a, T b) { if(a < b) {a = b; return true;} return false; }
const int INF = 1LL << 60;

signed main() {
	int n;
	int r;
	cin >> n >> r;

	if(n >= 10) cout << r << endl;
	else {
		cout << r + 100 * (10 - n) << endl;
	}
	
	return 0;
}
