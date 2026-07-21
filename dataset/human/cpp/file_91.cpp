#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

int main(void)
{
	int r, g, b, n, count = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n / r; i++)
	{
		for (int j = 0; j <= n / g; j++)
		{
			if (n - i * r - j * g == 0) { count++; }
			else if (n - i * r - j * g > 0 && (n - i * r - j * g) % b == 0) { count++; }
		}
	}
	cout << count << endl;
	return 0;
}
