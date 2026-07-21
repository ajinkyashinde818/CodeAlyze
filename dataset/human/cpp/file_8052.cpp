#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<deque>
#include<tuple>
#include<queue>
#include<map>
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>


#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define Endl endl
#define F first
#define S second

namespace mp = boost::multiprecision;

using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<ll>sum(n);
	bool flag = false;
	rep(i, n) {
		int a;
		cin >> a;
		if (flag) {
			sum[i] = sum[i - 1] + a;
		}
		else {
			sum[i] = a;
			flag = true;
		}
	}
	ll tmp = 1e10;
	rep(i, n-1) {
			tmp = min(tmp,abs(sum[n - 1] - sum[i] * 2));
	}
	cout << tmp << endl;

}
