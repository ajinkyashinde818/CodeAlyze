#include <iostream>
#include<string>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<map>
using namespace std;

int main() {
	int N, R;
	cin >> N>>R;
	if (N < 10) {
		cout << R + 100 * (10 - N) << endl;
	}
	else {
		cout << R << endl;
	}
	return 0;
}
