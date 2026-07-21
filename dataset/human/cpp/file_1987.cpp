#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n; long long int sum = 0; bool b = false;
	cin >> n;
	vector<long long int>num(n);

	for (int i = 0; i < n; i++) {
		long long int a;
		cin >> a;
		num[i] = a;
	}
	
	for (int i = 0; i < n-1; i++) {
		if (num[i] < 0) {
			num[i] = num[i] * -1;
			num[i + 1] = num[i + 1] * -1;
		}
	}

	if (num[n - 1] < 0) {
		b = true;
	}

	for (int i = 0; i < n; i++) {
		num[i] = abs(num[i]);
	}

	sort(num.begin(), num.end());

	if (b) {
		for (int i = 1; i < n; i++) {
			sum = sum + num[i];
		}
		cout << sum - num[0];

	}
	else {
		for (int i = 0; i < n; i++) {
			sum = sum + num[i];
		}
		cout << sum;
	}
	
	
	


}
