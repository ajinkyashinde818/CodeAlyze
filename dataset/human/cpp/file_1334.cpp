#include <iostream>

using namespace std;

int main()
{
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int count = 0;
	for (int r = 0; r <= N; r++) {
		for (int g = 0; g <= N; g++) {
			int v = R * r + G * g;
			if (N >= v && (N - v) % B == 0) {
				count++;
			}
		}
	}
	cout << count << endl;
}
