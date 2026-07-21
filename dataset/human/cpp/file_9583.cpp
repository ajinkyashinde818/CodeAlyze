#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define inf 10000000000000007
#define vsort(vec) sort(vec.begin(),vec.end())
#define vreverse(vec) reverse(vec.begin(),vec.end())
#define ggr getchar(); getchar();return 0;
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}

int n, m;
char a[50][50], b[50][50];
bool ta;

signed main() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			cin >> a[i][j];
		}
	}
	rep(i, m) {
		rep(j, m) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			ta = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l])ta = false;
				}
			}
			if (ta) {
				cout << "Yes" << endl;
				ggr
			}
		}
	}
	cout << "No" << endl;
	ggr
}
