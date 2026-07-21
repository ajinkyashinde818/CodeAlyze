#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int R, G, B, N;

	cin >> R >> G >> B >> N;

	int count = 0;

	for(int r = 0 ; r <= N/R ; r++)
	{
		for (int g = 0; g <= (N - r * R) / G; g++)
		{
			if ((N - r * R - g * G) % B == 0)
			{
				count++;
			}
		}

	}

	cout << count << endl;

	return 0;
}
