#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;


int main(){

	int N;
	long long absSum = 0;
	int input;
	int smallest = 1000000000;
	bool Minus = false;
	long long answer = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input < 0) Minus = !Minus;
		absSum += abs(input);
		smallest = min(smallest, abs(input));
	}

	if(Minus) answer = absSum - 2 * smallest;
	else answer = absSum;

	cout << answer;

	return 0;
}
