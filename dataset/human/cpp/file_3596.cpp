#include <bits/stdc++.h>

int calcGCD(int, int);

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int> A(N);
	for (auto& e: A) scanf("%d", &e);
	int minus{}, zero{};
	for (auto& e: A)
		if (e < 0)
			minus++;
		else if (e == 0)
			zero++;

	long long sum{};
	for (auto& e: A) sum += std::abs(e);
	if (zero == 0 && minus % 2 == 1)
	{
		int min{1 << 30};
		for (auto& e: A) min = std::min(min, std::abs(e));
		sum -= 2 * min;
	}
	printf("%lld\n", sum);

	return 0;
}
