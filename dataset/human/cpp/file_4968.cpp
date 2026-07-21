#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void A_Beginner(void) {

	int N, R;
	cin >> N >> R;
	cout << ((N >= 10) ? R : R + 100 * (10 - N));
	return;
}

int main(void) {

	A_Beginner();
	return 0;
}
