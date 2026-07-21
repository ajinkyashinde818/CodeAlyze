#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


int main() {
	int r,g,b,n,ans=0;
	vector<int> rgb(3);
	cin >> rgb[1] >> rgb[2] >> rgb[3] >> n;
	sort(rgb.begin(),rgb.end());
	r = rgb[3];
	g = rgb[2];
	b = rgb[1];

	for (int i = 0; i <= n / r; i++) {
		for (int j = 0; j <= (n - (r * i)) / g; j++) {
			if ((n - (r * i) - (g * j) )% b == 0)ans++;
			}
		}
	
	cout << ans << endl;
	return 0;
}
