#include <bits/stdc++.h>
using namespace std;
long long f(int N, long long C, const vector<long long>& X, const vector<long long>& V) {
	long long r = 0;
	vector<long long> a1(N+1);
	vector<long long> a2(N+1);
	for (int i = 0; i < N; ++ i) a1[i+1] = a1[i] + V[i];
	for (int i = 0; i < N; ++ i) a2[i+1] = a2[i] + V[N-1-i];

	for (int i = 0; i < N; ++ i) r = max(r, a1[i+1]-X[i]);

	vector<long long> a3(N+1);
	for (int i = 0; i < N; ++ i) a3[i+1] = a1[i+1] - 2*X[i];

	vector<long long> a4(N+1);
	for (int i = 0; i < N; ++ i) a4[i+1] = a2[i+1] - (C-X[N-1-i]);

	vector<long long> a5(N+1);
	for (int i = 0; i < N; ++ i) {
		a5[i+1] = max(a5[i], a4[i+1]);
	}

	for (int i = 0; i < N; ++ i) {
		//cerr << a3[i+1] + a5[N-1-i] << endl;
		r = max(r, a3[i+1] + a5[N-1-i]);
	}

	return r;
}
int main() {
	int N;
	long long C;
	cin >> N >> C;
	vector<long long> X(N), V(N);
	for (int i = 0; i < N; ++ i) cin >> X[i] >> V[i];
	long long r = f(N,C,X,V);
	reverse(X.begin(), X.end());
	reverse(V.begin(), V.end());
	for (auto& x : X) x = C - x;
	r = max(r, f(N,C,X,V));
	cout << r << endl;
}
