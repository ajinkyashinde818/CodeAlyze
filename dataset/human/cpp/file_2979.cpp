#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
using namespace std;

int main()
{
	int N = 0;
	std::vector<long> A;

	//数
	cin >> N;
	long min = std::numeric_limits<long>::max();
	int minusNum = 0;
	for (int i = 0; i < N; i++) {
		long tmp;
		cin >> tmp;
		A.push_back(tmp);
		if (min > abs(tmp)) {
			min = abs(tmp);
		}
		if (tmp < 0) {
			minusNum++;
		}
	}

	//変換する
	bool ischanged = false;
	if (minusNum % 2 == 0) {
		for (int i = 0; i < N; i++) {
			A[i] = A[i] < 0 ? A[i] * -1 : A[i];
		}
	} else {
		for (int i = 0; i < N; i++) {
			if (abs(A[i]) == min && !ischanged) {
				ischanged = true;
				A[i] = A[i] < 0 ? A[i] : A[i]*-1;
			} else {
				A[i] = abs(A[i]);
			}
		}
	}

	long sum = accumulate(A.begin(), A.end(), 0L);

	cout << sum << endl;
	
	return 0;
}
