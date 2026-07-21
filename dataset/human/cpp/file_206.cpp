#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int r, g, b, n, x, y;
	int c = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n / r; i++){
		x = n - (r * i);
		for (int j = 0; j <= x / g; j++){
			y = x - (g * j);
			if (y % b == 0) c++;
		}
	}
	cout << c << endl;

	return 0;
}
