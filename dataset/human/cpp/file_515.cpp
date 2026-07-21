#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
int main(){
	int a[3], n, cnt = 0;
	cin >> a[0] >> a[1] >> a[2] >> n;
	sort ( a, a + 3 );
	for (int x = 0; x <= n / a[2]; ++x) {
		for (int y = 0; y <= (n - x * a[2])/a[1]; ++y) {
			if ((((n - x * a[2] )- y * a[1]) % a[0]) == 0) cnt = cnt + 1;
		}
	}
	cout << cnt << endl;

}
