#include <cmath>
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main(int, char**)
{
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int count = 0;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (n >= (i * r + j * g) && (n - (i * r + j * g)) % b == 0)
			{
				++count;
			}
		}
	}
	cout << count << endl;
	return 0;
}
