#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "math.h"
using namespace std;
int main()
{
	vector<long long> a;
	long long n;
	cin >> n;

	for (long long i = 0; i < n; i++) {
		long long kari;
		cin >> kari;
		a.push_back(kari);
	}

	//long long sum = accumulate(a.begin(), a.end(), 0);
	//これだとaccumulateの第三引数がintとみなされ、オーバーフローの恐れ！
	long long sum = accumulate(a.begin(), a.end(), 0LL);


	long long sumima = 0, minimam = 1000000000000000000LL;
	for (long long i = 0; i < n - 1; i++) {
		sumima += a[i];
		if (abs(sum - 2 * sumima) < minimam) {
			minimam = abs(sum - 2 * sumima);
		};
	}

	cout << minimam<<endl;
	return 0;

}
