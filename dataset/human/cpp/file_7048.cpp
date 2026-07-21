#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int> A(N), B(N);
	std::vector<std::pair<int, int>> num(N + 1);
	for (int i{}; i <= N; i++)
		num[i].second = i;
	num.reserve(2 * N);
	for (auto& e: A)
	{
		scanf("%d", &e);
		num[e].first++;
	}
	for (auto& e: B)
	{
		scanf("%d", &e);
		num[e].first++;
	}
	std::sort(num.rbegin(), num.rend());
	if (num.front().first > N)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	std::reverse(B.begin(), B.end());
	
	int change{};
	for (int i{}; i < N; i++)
	{
		if (A[i] != B[i]) continue;
		while (A[change] == A[i] || B[change] == A[i])
			change++;
		std::swap(B[i], B[change]);
		change++;
	}
	for (int i{}; i < N; i++)
		printf("%d%c", B[i], i + 1 == N? '\n': ' ');

	return 0;
}
