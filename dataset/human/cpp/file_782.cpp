#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <tuple>
#include <regex>
#include <map>
#include <bitset>

using namespace std;
using ull = unsigned long long;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

#define EPS (1e-7) 
#define ALL(x) begin(x), end(x)

int main() {
	size_t R, G, B, N;
	cin >> R >> G >> B >> N;

	vector<ull> rgVec;
	ull ans = 0;
	for (size_t r = 0; r <= N; r++) {
		const ull rr = r * R;
		if (rr > N) break;
		for (size_t g = 0; g <= N; g++) {
			const ull gg = g * G;
			const ull rg = rr + gg;
			if (rg <= N) {
				if ((N - rg) % B == 0) {
					ans++;
				}
			} else {
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
