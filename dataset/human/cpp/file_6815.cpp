#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int M = 1 << 19;
int S[M * 2+10];

void update(int k, int h) {

	S[k + M] += h;

	int p = (k + M) / 2;

	while (p >= 1) {

		if (S[p * 2] >= S[p * 2 + 1]) { S[p] = S[p * 2]; }
		else { S[p] = S[p * 2 + 1]; }
		p /= 2;
	}

}

int Q(int a, int b, int l=0, int r=M-1, int k=1) {

	if (b < l || r < a) { return 0; }

	if (a <= l && r <= b) { return S[k]; }

	int tmp1 = Q(a, b, l, (l + r) / 2, k * 2);

	int tmp2 = Q(a, b, (l + r) / 2 + 1, r, k * 2 + 1);

	return max(tmp1, tmp2);
}

int N;
int A[200005], B[200005];

int C[200005];

set<int> G[200005];

int D[200005];

int CHECK(void) {

	for (int i = 1; i <= N; i++) {
		if (A[i] == D[i]) { return -1; }
	}

	return 1;

}

int main(void) {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> B[i];
		C[B[i]]++;
		update(B[i], 1);
	}

	for (int i = 1; i <= N; i++) {
		if (C[i] > 0) { G[C[i]].insert(i); }

	}


	/*for (int i = 1; i <= N; i++) {
		cout << "G[" << i << "]: ";
		for (auto y : G[i]) { cout << " " << y; }cout << endl;
	}*/


	/*for (int i = 1; i <= 3; i++) {
		cout << "Q(" << i << "," << N << ")= " << Q(i, N) << endl;
	}*/

	for (int i = 1; i <= N; i++) {
		int num = Q(A[i] + 1, N);
		if (num == 0) { num = Q(1, A[i]-1); }

		//cout << "num= " << num << endl;

		if (num == 0) { cout << "No" << endl; return 0; }
		
		auto it = G[num].end(); it--;
		if (*it == A[i]) { it--; }
		D[i] = *it;
		//cout << "D["<<i<<"]= " << D[i] << endl;
		G[num].erase(D[i]);
		if (num > 1) { G[num - 1].insert(D[i]); }

		//cout << "check" << endl;
		update(D[i], -1);
	}

	/*for (int i = 1; i <= N; i++) {
		cout << " " << D[i];
	}cout << endl;
	*/

	if (CHECK() == -1) { cout << "No" << endl; }
	else {
		cout << "Yes"<<endl;
		for (int i = 1; i <= N; i++) {
			if (i != 1) { cout << " "; }
			cout << D[i];
		}cout << endl;
	}
	return 0;
}
