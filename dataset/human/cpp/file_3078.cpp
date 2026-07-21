#include <iostream>

using namespace std;

const int N = (int)2*1e5;
typedef long long ll;
int a[N];
int n;
ll c[2][N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	c[0][0] = a[0];
	c[1][0] = -a[0];
	for (int i = 1; i < n; i++) {
		c[0][i] = max(c[0][i-1] + a[i], c[1][i-1] - a[i]);
		c[1][i] = max(c[0][i-1] - a[i], c[1][i-1] + a[i]);
	}
	cout << c[0][n-1] << endl;
}
