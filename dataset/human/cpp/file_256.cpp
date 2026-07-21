#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int cnt = 0;
	for (int i = 0; i <= 3000; i++) {
		int R = r*i;
		if (R > n) break;
		for (int j = 0; j <= 3000; j++) {
			int G = g*j;
			int RG = R + G;
			if (RG > n) break;
			int rest = (n - RG);
			if(rest%b==0) cnt++;

		}
	}
	cout << cnt;
	return 0;
}
