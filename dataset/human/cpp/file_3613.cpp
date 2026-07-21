#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>

using namespace std;

using ll = long long;
using ui = unsigned int;
const ll MOD = 1000000007;

//125
int main() {
	ll N;
	scanf("%lld", &N);

	ll abs_min = 100000000000;
	ll sum = 0;
	ll count_negative = 0;
	ll count_zero = 0;
	for (ll i = 0; i < N; i++) {
		ll num;
		scanf("%lld", &num);
		abs_min = std::min(std::abs(num), abs_min);

		if (num < 0) {
			count_negative++;
		}
		else if (num == 0) {
			count_zero++;
		}

		sum += std::abs(num);
	}

	ll result = 0;
	if (count_zero > 0) {
		result = sum;
	}
	else if (count_negative % 2 == 0) {
		result = sum;
	}
	else {
		result = sum - abs_min * 2;
	}

	printf("%lld\n", result);

	return 0;
}

//124
/*
int main() {
	ll N, K;
	scanf("%lld %lld", &N, &K);

	char s[100010];
	scanf("%s", &s);

	vector<ll> state_length; //index0,2,4,...�͋t����

	int prev_state = 1; //�ŏ��������Ƃ�����index0��0������悤��
	ll length = 0;
	for (ll i = 0; i < N; i++) {
		char c = s[i];
		if (c == '0') {
			//��
			if (prev_state == 0) {
				length++;
			}
			else {
				state_length.push_back(length);
				length = 1;
				prev_state = 0;
			}
		}
		else {
			//�t
			if (prev_state == 1) {
				length++;
			}
			else {
				state_length.push_back(length);
				length = 1;
				prev_state = 1;
			}
		}
	}
	state_length.push_back(length);
	if (prev_state == 1) {
		state_length.push_back(0); //�Ō�͐��ŏI���悤��
	}
	else {
		state_length.push_back(0);
		state_length.push_back(0); //�Ō�͐��ŏI���悤��
	}

	ll state_length_size = (ll)state_length.size();
	ll window = std::min(state_length_size, 1 + K * 2);
	ll start = 0;
	ll end = window;
	ll sum = 0;
	for (int i = start; i < end; i++) {
		sum += state_length[i];
	}
	ll max = sum;

	while (true) {
		start += 2;
		end += 2;
		if (end >= state_length_size) {
			break;
		}

		sum -= state_length[start - 2];
		sum -= state_length[start - 1];
		sum += state_length[end - 2];
		sum += state_length[end - 1];

		if (sum > max) {
			max = sum;
		}
	}

	printf("%lld\n", max);

	return 0;
}
*/
