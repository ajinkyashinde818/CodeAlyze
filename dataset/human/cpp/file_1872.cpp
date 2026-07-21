#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;

string S;
char T[17] = "0123456789abcdef";
int Q;
int U[32];
int power[4] = { 1,2,4,8 };

void Bit(string W) {
	int c[8], v[32];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 16; j++) {
			if (W[i] == T[j]) {
				c[i] = j;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 3; j >= 0; j--) {
			v[cnt] = (c[i] / power[j]) % 2;
			cnt++;
		}
	}
	for (int i = 0; i < 32; i++) {
		U[i] = v[31 - i];
	}
}

int Seisu() {
	int res2 = 0;
	for (int i = 8; i < 31; i++) {
		res2 += (1 << (i - 8))*U[i];
	}
	return res2;
}

int Shosu() {
	int res3 = 0;
	for (int i = 0; i < 8; i++) {
		res3 += (1 << i)*U[i];
	}
	return res3;
}

long double solve(string V) {
	Bit(V);
	int seisu = Seisu();
	int shosu = Shosu();
	long double ans = 1.0*seisu;
	long double ans2 = 1.0*shosu;
	ans += ans2 / 256.0;
	return ans;
}

int main() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> S;
		long double f = solve(S);
		long long g = f * 200000000;
		bool ok = false;
		if (U[31] == 1) { cout << '-'; }
		for (int i = 18; i >= 9; i--) {
			long long h = (g / (long long)pow(10, i)) % 10;
			if (h >= 1) { ok = true; }
			if (ok == true) { cout << h; }
		}
		cout << (g / (long long)pow(10, 8)) % 10;
		cout << '.';
		ok = true;
		for (int i = 7; i >= 0; i--) {
			int h = (g / (long long)pow(10, i)) % 10;
			if (ok == true || i == 7) {
				cout << h;
			}
			if (g % (long long)(pow(10, i)) == 0) {
				ok = false;
			}
		}
		cout << endl;
	}
	return 0;
}
