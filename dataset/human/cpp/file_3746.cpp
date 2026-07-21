#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
	int n;
	vector<int> a;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	ll sum = 0;
	int count_minus = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			a[i] = -a[i];
			count_minus++;
		}
		sum += a[i];
	}


	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cout << sum << endl;
			return 0;
		}
	}

	if (count_minus % 2 == 0) {
		cout << sum << endl;
		return 0;
	}

	int min = 1000000000;
	for (int i = 0; i < n; i++)
		if (min >= a[i])
			min = a[i];
	cout << sum - min * 2 << endl;
	return 0;
}
