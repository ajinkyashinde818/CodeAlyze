#include<iostream>
#include<algorithm>

int main() {
	long long N = 0;
	long long A[100000];
	long long count = 0;
	long long max = 0;
	
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
		if (A[i] < 0) {
			A[i] *= -1;
			count++;
		}
	}

	std::sort(A, A + N);

	if (count % 2 == 0) {
		for (int i = 0; i < N; i++) {
			max += A[i];
		}
	}
	else if (count % 2 == 1) {
		for (int i = 1; i < N; i++) {
			max += A[i];
		}
		max -= A[0];
	}

	std::cout << max << std::endl;

}
