#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	array<int,3> rgb;
	cin >> rgb[0] >> rgb[1] >> rgb[2] >> n;

	sort(rgb.begin(), rgb.end(), greater<int>());

	int maxI = n / rgb[0];
	int maxJ = n / rgb[1];
	int ret = 0;
	for (int i = 0; i <= maxI; ++i) {
		for (int j = 0; j <= maxJ; ++j) {
			int diff = n - (i * rgb[0] + j * rgb[1]);
			if (0 <= diff && diff % rgb[2] == 0) {
				++ret;
			}
		}
	}

	cout << ret << endl;

	return 0;
}
