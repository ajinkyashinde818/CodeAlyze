#include <iostream>
#include <numeric>
#include <stdio.h>
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
int Max(int(a), int(b), int(c)) {
	return max(max(a,b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}





int main() {
	string s = "No";
	int N,M;
	cin >>N>>M;
	vector<string> A(N);
	vector<string> B(M);


	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> B.at(i);
	}
	rep(i, N - M + 1) {
		rep(j, N - M + 1) {
			int l = 0;
			rep(h, M) {
				rep(w, M) {
					if (A.at(i + h).at(j + w) != B.at(h).at(w)) {
						l = 1;
					}
				}
			}
			if (l == 0) {
				s = "Yes";
			}
		}
	}
	cout << s << endl;
}
