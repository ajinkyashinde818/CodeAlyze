#include <iostream>
using namespace std;

struct neta {
	long long pos;
	long long cal;
};

neta sushi[100002];
neta sum_lt[100002];
neta sum_rt[100002];


int main()
{
	int N;
	long long C;
	cin >> N >> C;

	sushi[0].cal = 0;
	sushi[0].pos = 0;
	sum_lt[0].cal = 0;
	sum_lt[0].pos = 0;
	sum_rt[0].cal = 0;
	sum_rt[0].pos = 0;
	sushi[N+1].cal = 0;
	sushi[N+1].pos = C;
	sum_lt[N+1].cal = 0;
	sum_lt[N+1].pos = 0;
	sum_rt[N+1].cal = 0;
	sum_rt[N+1].pos = 0;

	long long cal_sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> sushi[i].pos >> sushi[i].cal;
		cal_sum += (sushi[i].cal - (sushi[i].pos - sushi[i-1].pos));
		if (cal_sum > sum_lt[i-1].cal) {
			sum_lt[i].cal = cal_sum;
			sum_lt[i].pos = sushi[i].pos;
		} else {
			sum_lt[i] = sum_lt[i-1];
		}
	}

	cal_sum = 0;
	for (int i = N; i >= 1; i--) {
		cal_sum += (sushi[i].cal - (sushi[i+1].pos - sushi[i].pos));
		if (cal_sum > sum_rt[i+1].cal) {
			sum_rt[i].cal = cal_sum;
			sum_rt[i].pos = C - sushi[i].pos;
		} else {
			sum_rt[i] = sum_rt[i+1];
		}
	}

	long long ans = 0;
	// clockwise
	for (int i = 0; i <= N; i++) {
		long long get_calorie = 0;
		get_calorie += sum_lt[i].cal;
		ans = max(ans, get_calorie);

		get_calorie -= (sum_lt[i].pos);
		get_calorie += sum_rt[i+1].cal;

		ans = max(ans, get_calorie);
	}

	// counter clockwise
	for (int i = N+1; i >= 1; i--) {
		long long get_calorie = 0;

		get_calorie += sum_rt[i].cal;
		ans = max(ans, get_calorie);

		get_calorie -= (sum_rt[i].pos);
		get_calorie += sum_lt[i-1].cal;

		ans = max(ans, get_calorie);
	}
	cout << ans << endl;

	return 0;
}
