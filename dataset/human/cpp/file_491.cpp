#include <iostream>

using namespace std;

int main(void) {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int count = 0;
	for (int r = 0; r <= N; r+=R)
	{
		for (int g = 0; g <= N; g+=G)
		{
			int b = N - r - g;
			if (b >= 0 && b%B == 0)
			{
				count++;
			}
		}
	}

	cout << count << endl;
	return 0;
}
