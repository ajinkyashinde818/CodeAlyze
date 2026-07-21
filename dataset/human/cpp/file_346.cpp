#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int r, g, b, n, counts=0;

int main() {
	cin >> r >> g >> b >> n;

	for (int i = 0; i <= 3000; ++i)
	{
		for (int j = 0; j <= 3000; ++j)
		{
			int s = n - (r*i + g*j);
			if (s >= 0 && s%b == 0)
			{
				counts++;
			}
		}
	}

	cout << counts << endl;

}
