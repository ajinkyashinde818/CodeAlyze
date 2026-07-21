#include <iostream>
using namespace std;

long long int avd(long long int a, long long int b) {

	if (a < b)return b - a;
	else return a - b;

}
int main() {

	int N;
	int a[200010];
	long long int all_sum, sunuke, dif;

	all_sum = 0;
	sunuke = 0;
	dif = 2147483647;
	
	cin >> N;
	for (int i = 1; i <= N; i++) {

		cin >> a[i];

	}

	for (int i = 1; i <= N; i++) {

		all_sum += a[i];

	}
	for (int i = 1; i < N; i++) {

		sunuke += a[i];
		if (dif > avd(sunuke, all_sum - sunuke)) {

			dif = avd(sunuke, all_sum - sunuke);

		}

	}

	cout << dif << endl;
	
	return 0;
}
