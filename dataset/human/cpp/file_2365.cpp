#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	unsigned long long sum = 0ull, minA = 1000000001ull;
	bool isMinusNumOdd = false;
	bool isZeroExists = false;
	int n;
	cin >> n;
	
	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		sum += abs(temp);
		minA = min(minA, (unsigned long long)abs(temp));
		if (temp < 0)isMinusNumOdd = !isMinusNumOdd;
		if (temp == 0)isZeroExists = true;
	}

	if (!isZeroExists && isMinusNumOdd)sum -= (minA * 2);

	cout << sum << endl;
	return 0;
}
