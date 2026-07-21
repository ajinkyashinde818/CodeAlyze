#include <iostream>
#include <string>
#include <sstream>  // istringstream
#include <vector>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;

	std::vector<long> vctA(N, 0);
	std::vector<long long> vctSum(N, 0);
	// std::vector<long long> vctSumRvs(N, 0);

	long long sum = 0;
	std::vector<long long>::iterator is = vctSum.begin();
	for (int i = 0; i < N; ++i){
		int curA = 0;
		cin >> curA;
		sum += curA;
		*is = sum;
		if (i < N - 1){
			++is;
		}
	}

	is = vctSum.begin();
	long long minDiff = 0;

	for (int i = 0; i < N -1; ++i){
		long long diff = std::abs(sum - 2 * *is);
		if (i == 0){
			minDiff = diff;
		}
		else if (diff < minDiff){
			minDiff = diff;
		}
		++is;
	}

	cout << minDiff;

	return 0;
}
