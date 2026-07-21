#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int r, g, b, n, i, j, counter;
    counter = 0;
	cin >> r >> g >> b >> n;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if ((n - (r * i + g * j)) % b == 0&&(n - (r * i + g * j))>=0){counter++;}
		}
	}
	cout << counter << endl;
}
