#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;
const int MAX = 200000;
const int N = 100;

long long S[MAX];

int main() {
	int n; cin>>n;
	rep(i, n) {
		long long a; cin>>a;
		if(i>0) S[i]=S[i-1]+a;
		else S[i]=a;
	}
	long long ans = INFL;
	rep(i, n-1) ans = min(ans, abs(S[n-1]-2*S[i]));
	cout << ans << endl;
}
