//
//  lib.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

function<void()> createFunc() {
	int x = 1;
	return [&x](){cout << x << endl;};
}

int main() {
	int N;
	cin >> N;
	vector<ll> ais;
	for (int i = 0; i < N; i++) {
		ll ai;
		scanf("%lld", &ai);
		ais.push_back(ai);
	}
	vector<ll> dp, dp_neg;
	dp.resize(N);
	dp[N-1]=ais[N-1];
	dp_neg.resize(N);
	dp_neg[N-1]=-ais[N-1];
	for (int i = 1; i < N; i++) {
		dp[N-1-i] = max(ais[N-1-i]+dp[N-i], -ais[N-i-1]+dp_neg[N-i]);
		dp_neg[N-1-i] = max(-ais[N-1-i]+dp[N-i], ais[N-i-1]+dp_neg[N-i]);
	}
	cout << dp[0] << endl;
}
