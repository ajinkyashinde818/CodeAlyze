#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll inf = 100000000;
typedef pair<ll, ll> P;
int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	ll count = 0;
	for (int i = 0; i <= n / r; i++) {
		for (int j = 0; j <= n / g; j++) {
			int z = n - (i * r + j * g);
			if (z % b == 0&&z>=0) {
				count++;
				
			}
		}
	}
	cout << count << endl;
	return 0;
}
