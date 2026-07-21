#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stdio.h>

using namespace std;

int main() {
	int N,R;
	cin >> N >> R;
	
	if (N < 10) {
		R += 100 * (10 - N);
	}

	cout << R << endl;

	return 0;
}
