#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#include <numeric>
#include <bitset>
#include <cassert>

using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)



int main() {
	int N;
	vector<ll> A;
	cin >> N;
	A.resize(N);
	ll total = 0;
	int count = 0;
	ll min_tmp = INF;
	rep(i, N) {
		cin >> A[i];
		total += abs(A[i]);
		if (A[i] < 0) {
			count++;
		}
		chmin(min_tmp, abs(A[i]));
	}
	if (count % 2 == 0) {
		cout << total;
	}
	else {
		cout << total - 2 * min_tmp;
	}

	return 0;
}
