#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<deque>
#include<iomanip>
#include<ctime>
using namespace std;

int main()
{
	unsigned short N, R;
	cin >> N >> R;

	if (N >= 10) {
		cout << R << endl;
	}
	else {
		cout << R + 100 * (10 - N) << endl;
	}

	return 0;
}
