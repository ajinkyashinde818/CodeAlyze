#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main() {
	int N;
	vector<int> a;
	int inputA;
	long sunuke = 0;
	long araiguma = 0;
	vector<long> answer;
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> inputA;
		a.push_back(inputA);
		araiguma += inputA;
	}

	for (int i = 0; i < N-1; i++) {
		sunuke += a[i];
		araiguma -= a[i];
		int num = abs(sunuke - araiguma);
		answer.push_back(abs(sunuke-araiguma));
	}

	ans = *min_element(answer.begin(), answer.end());
	
	cout << ans << endl;

	return 0;
}
