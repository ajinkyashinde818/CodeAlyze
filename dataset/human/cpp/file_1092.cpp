#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int main() {

	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int cnt = 0;

	for (int i = 0; i <= n/r; i++) {//500
		for (int j = 0; j <= n/g; j++) {//100
			
			int sum = r * i + g * j;//R,Gの個数
			if (sum <= n) {

				int others = n - sum;
							   
				if (others % b == 0) {
					cnt++;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
