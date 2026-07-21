#include <algorithm>
#include <bitset>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/irange.hpp>
#include <cmath>
#include <map>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define decn int n = 0; cin >> n
#define sort(v) sort(v.begin(), v.end())
#define in(type, n) type n = 0; cin >> n

using namespace std;
namespace mp = boost::multiprecision;
typedef long long ll;
const ll M = 1000000007;

int main(){
	int n, r;
	cin >> n >> r;

	if (n > 10) {
		cout << r;
		return 0;
	}

	cout << 100 * (10-n) + r;

	return 0;
}
