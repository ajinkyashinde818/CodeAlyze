#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>

using namespace std;
typedef long long ll;
#define endl '\n'

template<typename T>
inline bool chmin(T& x, T a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T a) {
	if (x <= a) { x = a; return true; }
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N; cin >> N;
	vector<ll> A(N), B(N);
	map<ll, int> mp;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (mp.find(A[i]) == mp.end()) { mp.insert({ A[i],1 }); }
		else { mp[A[i]]++; }
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		if (mp.find(B[i]) == mp.end()) { mp.insert({ B[i],1 }); }
		else { mp[B[i]]++; }
	}

	for (auto itr = mp.begin(); itr != mp.end(); itr++) {
		if (itr->second > N) { cout << "No" << endl; return 0; }
	}

	vector<int> imos_diff(N, 0);
	{
		int c0 = 0, d0 = 0;
		while (c0 < N && d0 < N) {
			if (A[c0] < B[d0]) {
				while (c0 < N - 1 && (A[c0] == A[c0 + 1])) { c0++; } c0++;
			}
			else if (A[c0] > B[d0]) {
				while (d0 < N - 1 && (B[d0] == B[d0 + 1])) { d0++; } d0++;
			}
			else {
				int c1 = c0, d1 = d0;
				while (c1 < N - 1 && (A[c0] == A[c1 + 1])) { c1++; } c1++;
				while (d1 < N - 1 && (B[d0] == B[d1 + 1])) { d1++; } d1++;
				// [c0, c1) and [d0, d1)

				// c0 - d1 + 1 <= offset < c1 - d0 → No]

				int u = c0 - d1 + 1;
				int v = c1 - d0;

				while (u < 0) { u += N, v += N; }
				while (u >= N) { u -= N, v -= N; }

				if (v > N) {
					imos_diff[0]++;
					imos_diff[v - N]--;
					imos_diff[u]++;
				}
				else {
					imos_diff[u]++;
					imos_diff[v]--;
				}
				c0 = c1;
				d0 = d1;
			}
		}
	}
	for (int i = 1; i < N; i++) {
		imos_diff[i] += imos_diff[i - 1];
	}

	int k = -1;
	for (int i = 0; i < N; i++) {
		if (imos_diff[i] == 0) { k = i; break; }
	}
	if (k == -1) { cout << "No" << endl; return 0; }
	
	cout << "Yes" << endl;
	for (int i = 0; i < N; i++) {
		cout << B[(i + N - k) % N] << " ";
	}

	return 0;
}
