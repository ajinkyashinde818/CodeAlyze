#include "iostream"
#include "algorithm"
using namespace std;

int main()
{
	int minNum = 1000000000,minasCount=0;
	int N, a[100000], x[100000];
	long long ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		if (a[i] < 0)
		{
			minasCount++;
		}
		x[i] = abs(a[i]);
		minNum = min(minNum, x[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ans += x[i];
	}
	if (minasCount % 2 == 1)
	{
		ans -= (minNum*2);
	}
	cout << ans << endl;
}
