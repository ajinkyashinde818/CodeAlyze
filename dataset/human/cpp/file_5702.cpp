#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define MAX 100002

bool use[MAX];
int dp[MAX];
inline int dfs(int a) {
	if (a == 0)return 0;
	if (use[a]) {
		return dp[a];
	}
	use[a] = true;
	set<int> s;
	vector<int> v;
	s.insert(0);
	for (int i = a - 1; i >= 0; i--) {
		v.push_back(dfs(i));
		int ar = 0;
		for (int j = 0; j < v.size(); j++) {
			ar ^= v[j];
		}
		s.insert(ar);
	}
	int c = 0;
	while (s.count(c)) {
		c++;
	}
	dp[a] = c;
	return c;
	
}
int n;
long long int l;
char buf[100002];
int go[100012][2];

string s;
int root;

vector<long long int> xr;
void dfs(int b,long long int dep) {
	if (go[b][0] == -1 && go[b][1] == -1) {
		//leave
		return;
	}
	if (go[b][0] == -1) {
		xr.push_back(dep);
	}
	else {
		dfs(go[b][0], dep - 1);
	}
	if (go[b][1] == -1) {
		xr.push_back(dep);
	}
	else{
		dfs(go[b][1], dep - 1);
	}

}
int main() {
	cin >> n ;
	scanf("%lld", &l);
	int sz = 1;
	memset(go, -1, sizeof(go));
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		s = buf;
		int cur = root;
		for (int j = 0; j < s.size(); j++) {
			int nex = s[j] - '0';
			if (go[cur][nex] == -1) {
				go[cur][nex] = sz;
				sz++;
			}
			cur = go[cur][nex];
		}
	}
	dfs(root,l);
	long long int X = 0;
	for (int i = 0; i < xr.size(); i++) {
		long long int val = xr[i];
		long long int cnt = 1;
		while (val % 2 == 0LL) {
			cnt <<= 1LL;
			val >>= 1LL;
		}
		X ^= cnt;
	}
	if (X) {
		puts("Alice");
	}
	else {
		puts("Bob");
	}
	return 0;
}
