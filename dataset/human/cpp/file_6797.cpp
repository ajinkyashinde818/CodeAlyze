#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	map<int,int> cnt;
	for (auto& x : A) { cin >> x; ++ cnt[x]; }
	for (auto& x : B) { cin >> x; ++ cnt[x]; }
	for (auto p : cnt) {
		if (p.second > N) {
			cout << "No" << endl;
			return 0;
		}
	}
	map<int,int> pA, qA;
	map<int,int> pB, qB;
	for (int i = 0; i < N; ++ i) {
		if (!pA.count(A[i])) pA[A[i]] = i;
		qA[A[i]] = i;
	}
	for (int i = 0; i < N; ++ i) {
		if (!pB.count(B[i])) pB[B[i]] = i;
		qB[B[i]] = i;
	}
	vector<int> hoge(N+1);
	int piyo = 0;
	for (auto pp : pB) {
		int x = pp.first;
		if (!pA.count(x)) continue;
		int p1 = pA[x];
		int q1 = qA[x];
		int p2 = pB[x];
		int q2 = qB[x];
		int d1 = (q1 + 1 - p2 + 2*N) % N;
		int d2 = (p1 - 1 - q2 + 2*N) % N;
		++ piyo;
		if (d1 <= d2) {
			++ hoge[d1];
			-- hoge[d2+1];
		} else {
			++ hoge[0];
			-- hoge[d2+1];
			++ hoge[d1];
		}
	}
	int s = 0;
	for (int i = 0; i < N; ++ i) {
		s += hoge[i];
		if (s == piyo) {
			cerr << i << endl;
			cout << "Yes" << endl;
			for (int j = 0; j < N; ++ j) {
				if (j) cout << " ";
				cout << B[(j-i+N) % N];
			}
			cout << endl;
			return 0;
		}
	}
	throw 1;
}
