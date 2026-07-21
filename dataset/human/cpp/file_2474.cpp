#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<map>

using namespace std;


int N;
int main() {

	cin >> N;
	long long sum = 0;
	long long hu = 0;
	long long minnum = 1000000000;
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;

		sum += abs(a);
		if (a < 0) hu++;

		minnum = min(minnum, abs(a));
	}

	cout << sum - minnum*(hu % 2)*2 << endl;


	return 0;
}
