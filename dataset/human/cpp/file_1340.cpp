#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int c, r, g, b, n, x, y;

int main(){

	cin >> r >> g >> b >> n;

	for (int i = 0; i <= n / r; i++){
		x = n - (i * r);
		for (int j = 0; j <= x / g; j++){
			y = x - (j * g);
			if (y % b == 0) c++;
		}
	}

	cout << c << endl;

	return 0;
}
