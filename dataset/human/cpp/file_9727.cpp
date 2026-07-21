#include<iostream>
#include<cstdlib>
using namespace std;

int max(int x, int y);
int min(int x, int y);
int gcd(int x, int y);	/*最大公約数*/
int lcm(int x, int y);	/*最小公倍数*/


int main()
{
	char alp[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	int n;
	cin >> n;

	char s[100000];
	cin >> s;

	int count[26];

	for (int i = 0;i < 26;i++)
	{
		count[i] = 0;

		for (int j = 0;j < n;j++)
		{
			if (s[j] == alp[i])
				count[i]++;
		}
	}

	long int ans = 1;

	for (int i = 0;i < 26;i++)
	{
		ans = ans * (count[i] + 1) % 1000000007;
	}

	if (ans == 0)
		ans = 1000000006;
	else
		ans--;

	cout << ans;

	return 0;
}

/*2数の大きい方を返す*/
int max(int x, int y)
{
	int max;

	if (x < y)
		max = y;
	else
		max = x;

	return max;
}

/*2数の小さい方を返す*/
int min(int x, int y)
{
	int min;

	if (x < y)
		min = x;
	else
		min = y;

	return min;
}

/*2数の最大公約数を返す*/
int gcd(int x, int y)
{
	int m;
	int gcd = 1;

	m = min(x, y);

	for (int i = 1;i <= m; i++)
	{
		if (x%i == 0 && y%i == 0)
			gcd = i;
	}

	return gcd;
}

/*2数の最小公倍数を返す*/
int lcm(int x, int y)
{
	int m;

	for (int i = 1;i <= y;i++)
	{
		if ((x*i) % y == 0) {
			m = x * i;
			break;
		}
	}

	return m;
}
