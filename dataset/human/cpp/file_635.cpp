#include <iostream>

using namespace std;

int main()
{
	int R, G, B, N;

	cin >> R >> G >> B >> N;

	int ret = 0;

	for (int r = 0; r * R <= N; r++)
	{
		for (int g = 0; r * R + g * G <= N; g++)
		{
			if ((N - r * R - g * G) % B == 0)
			{
				ret++;
			}
		}
	}

	cout << ret;

	return 0;
}
