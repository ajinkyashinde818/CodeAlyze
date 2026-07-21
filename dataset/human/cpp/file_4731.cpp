#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int llint;

llint N, R;

int main() {
	cin >> N >> R;

	if (N >= 10) {
		cout << R << endl;
	}
	else {
		cout << R + (100 * (10 - N)) << endl;
	}
}
