#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	long long int N, a[200005],sum  = 0,x = 0,ans = 1000000000000;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < N-1; i++) {
		sum -= a[i];
		x += a[i];
		ans = min(ans, abs(x - sum));
	}

	cout << ans << endl;

	return 0;
}
