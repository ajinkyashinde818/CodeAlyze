#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
using ll = long long int;
int n;
vector<ll> a;
ll suml = 0, sumr = 0;
ll ret = 1000000000000000;
int main(void) {
	cin >> n;
	for (size_t i = 0; i < n; i++){
		ll ai;
		cin >> ai;
		a.push_back(ai);
		sumr += ai;
	}
	for (int i = 0; i < n - 1; i++) {
		suml += a[i];
		sumr -= a[i];
		ll tmp = abs(suml - sumr);
		if (tmp < ret) {
			ret = tmp;
		}
	}
	cout << ret << endl;
	return 0;
}
