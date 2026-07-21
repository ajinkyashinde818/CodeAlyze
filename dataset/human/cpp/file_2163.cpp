#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include<math.h>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

long long gcd(long long x, long long y) {
	while (1) {
		if (x < y)swap(x, y);
		x %= y;
		if (x == 0)return y;
	}
}

int main() {
	int N,x=0,z; cin >> N;
	long long ans = 0,y=5e9;
	vector<long long> A(N),L(N),R(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (y > abs(A[i])) {
			y = abs(A[i]); z = i;
		}
		if (A[i] <= 0)x++;
	}
	if (x % 2 == 0) {
		for (int i = 0; i < N; i++) ans += abs(A[i]);
	}
	else{
		for (int i = 0; i < N; i++) { ans += abs(A[i]); }
		ans -= 2 * abs(A[z]);
	}
	cout << ans << endl;

}
