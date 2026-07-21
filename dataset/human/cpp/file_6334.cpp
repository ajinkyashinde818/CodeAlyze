#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<iterator>
#include<complex>
#include<stack>
using namespace std;
const long long mod_const = 1000000007;
using MIte = multimap<vector<long>, int>::iterator;

int main() {
	long N;
	cin >> N;

	string S;
	cin >> S;

	if (S[0] == 'W') {
		cout << "0" << endl;
		return 0;
	}

	vector<int> vLeft(2 * N, 0);
	long cnt1 = 0;
	for (int i = 0; i != 2 * N; ++i) {
		if (i % 2 == 1) {
			if (S[i] == 'B') {
				vLeft[i] = 0;
			}
			else if (S[i] == 'W') {
				vLeft[i] = 1;
				cnt1++;
			}
		}
		else {
			if (S[i] == 'B') {
				vLeft[i] = 1;
				cnt1++;
			}
			else if (S[i] == 'W') {
				vLeft[i] = 0;
			}
		}
	}

	vector<int> vRight(2 * N, 0);
	long cnt2 = 0;
	for (int i = 0; i != 2 * N; ++i) {
		if (i % 2 == 0) {
			if (S[i] == 'B') {
				vRight[i] = 0;
			}
			else if (S[i] == 'W') {
				vRight[i] = 1;
				cnt2++;
			}
		}
		else {
			if (S[i] == 'B') {
				vRight[i] = 1;
				cnt2++;
			}
			else if (S[i] == 'W') {
				vRight[i] = 0;
			}
		}
	}

	// vLeft[i] == vRight[i]となるiが一つでも存在したら答えは0通り
	bool fail = false;
	for (int i = 0; i != 2 * N; ++i) {
		if (vLeft[i] == vRight[i]) {
			fail = true;
			break;
		}
	}
	// vLeftとvRightで1となる数がNで同じにならなければ答えは0通り
	if ((cnt1 != N) || (cnt2 != N)) {
		fail = true;
	}
	if (fail) {
		cout << "0" << endl;
		return 0;
	}

	vector<long> v1(2 * N, 0);
	for (int i = (2 * N - 2); i >= 0; --i) {
		v1[i] = v1[i + 1] + vRight[i + 1];
	}

	long long ans1 = 1;
	long long used = 0;
	for (int i = (2 * N - 2); i >= 0; --i) {
		if (vLeft[i] == 1) {
			ans1 *= (v1[i] - used);
			ans1 = ans1 % mod_const;
			used++;
		}
	}

	for (int i = 1; i != N+1; ++i) {
		ans1 *= i;
		ans1 = ans1 % mod_const;
	}

	cout << ans1 << endl;

	return 0;
}
