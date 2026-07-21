#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long aRuiseki[n];
	cin >> aRuiseki[0];
	for(int i = 1; i < n; i++){
		int tmp;
		cin >> tmp;
		aRuiseki[i] = tmp + aRuiseki[i-1];
	}

	long long ans = llabs(aRuiseki[n-1] - aRuiseki[0] * 2);
	for(int i = 1; i <= n-2; i++){
		long long difference = llabs(aRuiseki[n-1] - aRuiseki[i] * 2);
		ans = min(ans, difference);
	}

	cout << ans << "\n";

	return 0;
}
