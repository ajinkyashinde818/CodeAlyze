#include <iostream>
using namespace std;

long long A, B, C, N, S;

int main() {
	cin >> A >> B >> C >> N;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			int Z = N - i * A - j * B;
			if (0 <= Z && Z % C == 0) S++;
		}
	}
	cout << S << endl;
	return 0;
}
