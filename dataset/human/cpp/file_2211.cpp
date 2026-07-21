#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;

const int INF = 1 << 29;	// 十分大きい値にする, INT_MAX にしないのはオーバーフロー対策

int main(void)
{
	int N;
	int A[100001];
	int min = INF;
	int minus_num = 0;
	long long sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;

		if (tmp >= 0) {
			A[i] = tmp;
		}
		else {
			A[i] = -tmp;
			minus_num++;
		}
		if (A[i] < min) {
			min = A[i];
		}
		sum += A[i];
	}
	
	if (minus_num % 2 == 1) {
		sum -= min * 2;
	}
	
	cout << sum << endl;

	return 0;
}
