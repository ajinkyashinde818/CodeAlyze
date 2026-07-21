#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long n, x;
	cin >> n;
	long long neg = 0, mini = int(1e9), sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		sum += abs(x);
		mini = min(mini, abs(x));
		if (x < 0) neg++;
	}
	
	if (neg % 2) sum -= 2*mini;
	cout << sum;
}
