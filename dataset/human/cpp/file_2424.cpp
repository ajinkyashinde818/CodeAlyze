#include<stdio.h>
#include<vector>
#include<algorithm>
int main()
{
	int N;
	scanf("%d", &N);

	std::vector<int> input(N, 0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	long long output = 0;
	int minuscount = 0;
	int minabs = 100000000;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		if (input[i] < 0) {
			minuscount++;
		}
		temp = std::abs(input[i]);
		minabs = std::min(minabs, temp);
		output += temp;
	}

	if (minuscount % 2 == 1) {
		output = output - (minabs * 2);
	}

	printf("%lld", output);

	return 0;
}
