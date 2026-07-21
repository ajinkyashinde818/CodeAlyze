#include <iostream>
using namespace std;



int main() {
	
	int n;
	long long a[100001];
	long long b[100001];
	int num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			b[i] = a[i];
		}
		else {
			num++;
			b[i] = -1 * a[i];
		}
	}
	
	
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += b[i];
	}
	if (num % 2 == 0) cout << sum;
	else {
		long long  min = 1000000001;

		for (int i = 0; i < n; i++) {
			if (b[i] < min) min = b[i];
		}
		sum = sum - 2 * min;
		cout << sum;
	}
	
	return 0;
}
