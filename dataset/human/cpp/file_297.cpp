#include <iostream>
using namespace std;

int main()
{
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	long long int ans = 0;
	for(auto i = 0; i <= n; ++i){
		if(i * r > n) break;
		for(auto j = 0; j <= n - r * i; ++j){
			if(i * r + j * g > n) break;
			if((n - r * i - j * g) % b == 0) ++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
