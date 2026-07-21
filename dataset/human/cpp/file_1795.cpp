#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD (1E9+7)
#define PI 3.1415926535897932384

std::ostream &operator<<(std::ostream &out, const vector<int> &tgt)
{
	string s;
	for (int i = 0; i<tgt.size(); i++) {
		s += (to_string(tgt[i]) + ((i != tgt.size() - 1) ? " " : ""));
	}
	out << s;
	return out;
}

int cas(int a, int b, int c, int d,int e) {
	return a * 10000 + b * 1000 + c * 100 + d * 10 + e;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, in;
	while (scanf("%d %d",&n,&m)==2) {
		stack<int> s;
		rep(i, m) {
			scanf("%d",&in);
			s.push(in);
		}
		vector<bool> b(n,true);
		while (!s.empty()) {
			if (b[s.top() - 1]) {
				printf("%d\n",s.top());
				b[s.top() - 1] = false;
			}
			s.pop();
		}
		rep(i, n) {
			if (b[i])printf("%d\n",i+1);
		}
	}
}
