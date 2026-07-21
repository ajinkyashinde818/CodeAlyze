#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>

// a 1000 → 1000
// ab 10 10 → 10 * 10 + 10 + 10


//abcd
//abc
//bcd
//acd
//abd
//ab/ac/ad
//bc/bd
//cd
//a/b/c/d
// 1 + 4 + 6  + 4 = 

using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)

const ll mod = 1000000007;

using namespace std;

int main() {
	int n;
	string s;

	cin >> n >> s;

	int a[28] = {};

	rep(i, s.size()) {
		a[s[i] - 'a'] ++;
	}
	ll ans = 1;

	rep (i, 26) {
		//cout << (char) (i + 'a') << ":" << a[i] << endl;
		if (a[i] > 0) {
			ans = ((a[i] + 1) * ans) % mod; 
		}
	
	}
	cout << ((ans - 1) + mod) % mod << endl;
	

 	return 0;
}
