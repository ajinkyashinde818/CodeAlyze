#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	long long int N, b = 0, a[100000 * 2] = {}, ans = 0, sum[100000 * 2 + 1] = {}, dif = 0, mini = 1000000000 * 2 + 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		b = (sum[N] - sum[i + 1]) - sum[i + 1];
		dif = abs(b);
		mini = min(dif, mini);
	}
	cout << mini;
	return 0;
}
