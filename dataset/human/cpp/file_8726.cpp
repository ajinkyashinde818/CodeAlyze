#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);++i)
#define erep(i,j,n) for(int i=(j);i<=(n);++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;

int main() {
	int n, m;
	cin >> n >> m;
	vs a(n), b(m);
	rep(i, 0, n) {
		cin >> a[i];
	}
	rep(i, 0, m) {
		cin >> b[i];
	}
	erep(i, 0, n - m) {
		erep(j, 0, n - m) {
			bool can = true;
			rep(k, 0, m) {
				rep(l, 0, m) {
					if (a[i + k][j + l] != b[k][l]) can = false;
				}
			}
			if (can) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
}
