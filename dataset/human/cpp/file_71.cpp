#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int main()
{
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	long long i1, i2, i3, i4, cnt = 0;
	for (i1 = 0; i1*r <= n; i1++) {
		for (i2 = 0; i1 * r + i2*g <= n; i2++) {
			if ((n - (i1 * r + i2 * g)) % b == 0)
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
