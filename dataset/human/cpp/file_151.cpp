#include <iostream>
#include <algorithm>
using namespace std;

int c[3], n, ans, tmp;

int main(){
	cin >> c[0] >> c[1] >> c[2] >> n;
	sort(c, c+3);
	ans = 0;
	for (int i = 0; i <= n/c[1]; ++i){
		for (int j = 0; j <= (n-i*c[1])/c[2]; ++j){
			tmp = n - i*c[1] - j*c[2];
			if (tmp < 0) break;
			else if (tmp % c[0] == 0) ans++;
		}
	}
	cout << ans;
}
