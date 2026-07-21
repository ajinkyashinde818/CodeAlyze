#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
struct P {
	ll time, pos;
};
struct T {
	ll time, can;
};
struct B {
	ll time, to;
};
ll a[100000];
T b[100000];
vector<B>e[100000];
const ll inf = 800000000000000;
int main() {
	int n, m;
	cin >> n >> m;
	char a[50][50], b[50][50];
	for (int i = 0; i < n; i++) {
		string u;
		cin >> u;
		for (int j = 0; j < n; j++) {
			a[i][j] = u[j];
		}
	}
	for (int i = 0; i < m; i++) {
		string u;
		cin >> u;
		for (int j = 0; j < m; j++) {
			b[i][j] = u[j];
		}
	}
	bool l = false;
	for (int i = 0; i <= (n - m); i++) {
		for (int j = 0; j <= (n - m); j++) {
			for (int x = 0; x < m; x++) {
				for (int y = 0; y < m; y++) {
					if (a[i + x][j + y] != b[x][y]) {
						goto stop;
					}
				}
			}
			l = true;
		stop:;
		}
	}
	if (l) cout << "Yes" << endl;
	else cout << "No" << endl;
}
