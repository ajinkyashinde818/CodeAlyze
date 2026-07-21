#include <iostream>
using namespace std;

int main() {
	int reding;
	int inputreding;
	int exreding;
	cin >> inputreding >> exreding;
	reding = exreding + (100 * (10 - inputreding));
	if (inputreding > 10)
		cout << exreding;
	else
		cout << reding;

	return 0;
}
