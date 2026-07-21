#include <iostream>
using namespace std;
#include <vector>
#include <string>

int main() {
  int R, G, B, N;
	cin >> R >> G >> B >> N;

	int g, b = 0, n = 0;

	for (g = 0; N - G * g >= 0; g++) {
		for (b = 0; N - G * g - B * b >= 0; b++) {
			if ((N - G * g - B * b) % R == 0) {
				n++;
			}
		}
	}
	cout << n;            //B
}
