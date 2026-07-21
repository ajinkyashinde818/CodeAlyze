#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
	long long n,temp,sum;
	sum = 0;
	std::vector<long long> v;
	std::cin >>  n;
	for (size_t i = 0; i < n; i++) {
		std::cin >> temp;
		sum += temp;
		v.push_back(temp);
	}
	long long sub = 0;
	long long submin = pow(10,10);

	for (size_t i = 0; i < n-1; i++) {
		sub += v[i];
		submin = min(submin, abs(sum - 2 * sub));
	}

	std::cout << submin << '\n';

	return 0;
}
