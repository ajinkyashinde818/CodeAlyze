#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int array[n];
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
		sum += array[i];
	}
	long long a = array[0];
	long long b = sum - array[0];
	long long answer = abs(a-b);
	for (int i = 1; i < n - 1; ++i)
	{
		a += array[i];
		b -= array[i];
		long long temp = abs(a-b);
		answer = min(answer, temp);
	}
	cout << answer;

	return 0;
}
