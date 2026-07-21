#include <iostream>
#include <cmath>
const int MAXN = 200000;
int cards[MAXN];

using namespace std;

int main() {
	int N;
	cin >> N;
	
	long long int left = 0, right = 0;
	for (int i = 0; i < N; ++i) {
		cin >> cards[i];
		left += cards[i];
	}
	left -= cards[N-1];
	right += cards[N-1];
	
	long long int lowest_diff = abs(left - right);
	for (int i = N-2; i >= 1; --i) {
		left -= cards[i];
		right += cards[i];
		
		if (abs(left - right) < lowest_diff) {
			lowest_diff = abs(left - right);
		}
	}
	
	cout << lowest_diff;
	return 0;
}
