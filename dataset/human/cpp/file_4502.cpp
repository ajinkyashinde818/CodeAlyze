#include <iostream>
#include <cmath>
using namespace std;

const int INF = 1<<25;
int main() {
	int t, d, ta, tb, da, db;
	cin >> t >> d >> ta >> tb >> da >> db;
	double ans = INF;
	for(int i = 0; da * i <= d; ++i){
		for(int j = 0; db * j <= d; ++j){
			if(da * i + db * j <= d){
				double temp = (ta * (da * i) + tb * (db * j)) / double((da * i) + (db * j));
				ans = min(ans, abs(t - temp));
			}
		}
	}
	cout << fixed << ans << endl;
	return 0;
}
