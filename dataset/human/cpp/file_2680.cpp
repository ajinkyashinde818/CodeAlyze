#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main()
{
	long n;
	cin >> n;
	long answer = 0;
	vector<long> b;
	long minus_answer = 0;
	long min = LONG_MIN;

	for (long i = 0; i < n; i++) {
		long k;
		cin >> k;
		answer += k;
		if (k < 0) {
			b.push_back(-k);
			minus_answer -= k;
		}
		if (min < -abs(k)) min = -abs(k);
	}

	if (b.size() % 2 == 0) {
		cout << answer + 2 * minus_answer << endl;
	}
	else {
		cout << answer + 2 * minus_answer - 2 * abs(min) << endl;
	}



    return 0;
}
