#include <iostream> 
#include <algorithm>

using namespace std;


using ll = long long;


int main() {
	int n;

	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll prev_plus = a[0] + a[1];
	ll prev_minus = - a[0] - a[1];

	for (int i = 2; i < n ; i++) {

		ll cur_plus = prev_plus + a[i];
		cur_plus = max(cur_plus, prev_minus + a[i]);

		ll cur_minus = prev_plus - a[i - 1] * 2 - a[i]; 
		cur_minus = max(cur_minus, prev_minus + a[i - 1] * 2 - a[i]);
	
		prev_plus =  cur_plus;
		prev_minus = cur_minus;
	}
	cout << max(prev_plus, prev_minus) << endl;

	return 0;

}
