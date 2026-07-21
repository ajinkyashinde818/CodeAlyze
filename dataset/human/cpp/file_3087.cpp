#include <iostream>
using namespace std;
long long int a[100010],n;



int main(){
	cin >> n;
	int e=0;
	long long int w = 1000000010;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= 0) {
			e++;
			a[i] = -a[i];	
		}
		if (a[i] < w) {
			w = a[i];
			}
	}
	long long int ans=0;
	for (int i = 0; i < n; i++) {
			ans += a[i];
		}

	if (e % 2 == 1) {
		ans -= 2*w;
	}
	cout << ans << endl;

return 0;
}
