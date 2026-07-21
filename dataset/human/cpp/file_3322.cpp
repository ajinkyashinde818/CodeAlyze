#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	int n, count = 0;
	long long int sum = 0;
	std::cin >> n;

	std::vector<long long int> v(n);
	for (long long int& x : v) {
		std::cin >> x;
	}


	for (int i = 0; i < n; i++) {
		if (v[i] < 0) {
			count++;
			v[i] = v[i] * -1;
		}
		sum += v[i];
	}

	if (count % 2 == 1) {
		int min = *min_element(v.begin(), v.end());

		sum = sum - 2 * min;
	}

	

	std::cout << sum << std::endl;
	return 0;
}
