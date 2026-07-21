#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

typedef long long ll;

int N;
int A[200000 + 10], B[200000 + 10];
int cnt[200000 + 10];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		cnt[A[i]]++;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		cnt[B[i]]++;
	}
	for (int i = 0; i <= 200000; i++) {
		if (cnt[i] > N) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	sort(B, B + N, greater<ll>());
	
	int samel = -1, samer = -1;//半開区間
	for (int i = 0; i < N; i++) {
		if (A[i] == B[i]) {
			if (samel == -1) {
				samel = i;
			}
		}
		else {
			if (samel != -1 && samer == -1) {
				samer = i;
			}
		}
	}
	if (samel != -1 && samer == -1)samer = N;

	int Al = -1, Ar = -1, Bl = -1, Br = -1;
	for (int i = 0; i < N; i++) {
		if (A[i] == A[samel]) {
			if (Al == -1)Al = i;
		}
		else {
			if (Al != -1 && Ar == -1)Ar = i;
		}
	}
	if (Al != -1 && Ar == -1)Ar = N;

	for (int i = 0; i < N; i++) {
		if (B[i] == B[samel]) {
			if (Bl == -1)Bl = i;
		}
		else {
			if (Bl != -1 && Br == -1)Br = i;
		}
	}
	if (Bl != -1 && Br == -1)Br = N;

	int tikanIdx = samel;
	for (int i = 0; i < min(Al, Bl) && tikanIdx < samer; i++, tikanIdx++) {
		swap(B[i], B[tikanIdx]);
	}
	for (int i = max(Ar, Br) + 1; i < N && tikanIdx < samer; i++, tikanIdx++) {
		swap(B[i], B[tikanIdx]);
	}
	for (int i = 0; i < N; i++) {
		cout << B[i];
		if (i != N - 1)cout << " ";
	}
	cout << endl;
	return 0;
}
