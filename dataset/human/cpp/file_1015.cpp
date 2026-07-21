#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int answer = 0;
	for (int i = 0; i <= n; i += r) {
		for (int j = 0; i + j <= n; j += g) {
			if ((n - i - j) % b == 0) answer++;
		}
	}

	cout << answer << endl;
    return 0;
}
