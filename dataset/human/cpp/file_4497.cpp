#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
double maxn = 114514.1919;
int T, D, a, b, c, d;
int main() {
	cin >> T >> D >> a >> b >> c >> d;
	for (int i = 0; i <= D; i += c) {
		for (int j = 0; j <= D; j += d) {
			if (i + j >= 1 && i + j <= D) {
				maxn = min(maxn, abs(T - (double)(a*i + b*j) / (i + j)));
			}
		}
	}
	cout << fixed << setprecision(15) << maxn << endl;
	return 0;
}
