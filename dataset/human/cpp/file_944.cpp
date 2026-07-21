#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int main() {
	long long int ans = 0, R, G, B, N;
	cin >> R >> G >> B >> N;
	for (int r = 0; r < N / R + 1; r++)
	{
		for (int g = 0; g < N / G + 1; g++)
		{
			if (N>=r*R+g*G)
			{
				if ((N - (r*R + g*G)) % B == 0)
				{
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
