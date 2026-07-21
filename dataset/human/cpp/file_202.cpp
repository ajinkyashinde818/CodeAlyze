#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int r, g, b, n;
	int count = 0;
	cin >> r >> g >> b >> n;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			int x = (n - (i * r + j * g))/b;
			if (x >= 0 && (i*r + j*g + x*b) == n) {
				++count;
			}
		}
	}
	
	cout << count << endl;
}
