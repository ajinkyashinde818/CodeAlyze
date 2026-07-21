#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <functional>

#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int maxR = N / R;
	int maxG = N / G;
	int maxB = N / B;

	long long result = 0;
	for (int i = 0; i <= maxR; i++)
	{
		if (i * R > N) break;
		for (int j = 0; j <= maxG; j++)
		{
			if (i * R + j * G > N) break;

			int left_box = N - (i * R + j * G);
			if (left_box % B == 0)
			{
				result++;
			}
		}
	}

	cout << result;

	return 0;
}
