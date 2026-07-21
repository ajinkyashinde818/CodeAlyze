#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	char s[200005];
	cin >> s;
	long long a = 1;
	int nest = 0;
	int i;
	for (i = 0; i < 2 * N; i++)
	{
		int x = i%2 ? -1 : 1;
		x *= s[i] == 'B' ? 1 : -1;
		if (x == -1)
		{
			a *= nest;
			a %= 1000000007;
		}
		nest += x;
		if (nest < 0)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	if (nest)
	{
		cout << 0 << endl;
		return 0;
	}
	for (i = 1; i <= N; i++)
	{
		a *= i;
		a %= 1000000007;
	}
	cout << a << endl;
	return 0;
}
