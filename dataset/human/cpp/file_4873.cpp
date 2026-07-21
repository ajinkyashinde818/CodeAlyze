#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;

int main() {

	int N;
	int R;

	cin >> N;
	cin >> R;

	if (N >= 10) {
		cout << R << endl;
	}
	else {
		int val = 100 * (10 - N);
		R = R + val;
		cout << R << endl;
	}

	return  0;
}
