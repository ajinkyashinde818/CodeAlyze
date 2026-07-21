#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

long long dp[3][100100] = {};
const long long INF = 1LL << 60;
#define MOD 1000000007

template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

/**
* @fn
* 最大値を取ります.Vector<int>を渡すこと.
*/
long long int imax(vector<int> a) {
	int MAX = -10000000;
	for (int i = 0; i < a.size(); i++) {
		if (MAX < a.at(i)) MAX = a.at(i);
	}
	return MAX;
}

/**
* @fn
* 最小値を取ります.Vector<int>を渡すこと.
*/
long long int imin(vector<int> a) {
	int MIN = 1000000000;
	for (int i = 0; i < a.size(); i++) {
		if (MIN > a.at(i)) MIN = a.at(i);
	}
	return MIN;
}


long long int absmin(vector<int> a, long long int b) {
	int mini = 100000000;
	int d = 0;
	for (int i = 0; i < a.size(); i++) {
		if (mini > abs(a.at(i) - b)) {
			mini = abs(a.at(i) - b);
			d = i;
		}
	}
	return d;
}

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	if (b < 1) return -1;
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

//ここまでライブラリ
//ここから本文

long long int tpimin(vector<int> a) {
	int MIN = 1000000000;
	int number = 0;
	for (int i = 0; i < a.size(); i++) {
		if (MIN > a.at(i)) MIN = a.at(i);
		number = i;
	}
	return number;
}



int main() {
	int m, n;
	cin >> n >> m;
	vector<string> a(m + 2);
	vector<string> b(n + 2);
	/*for (int i = 0; i < m + 2; i++) {
		a.at(i) = string(1000, 'a');
	}
	for (int i = 0; i < n + 2; i++) {
		b.at(i) = string(1000, 'a');
	}*/

	for (int i = 0; i < n; i++) {
		cin >> b.at(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> a.at(i);
	}
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			if (b.at(i).find(a.at(0).at(0)) != string::npos) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			for (int p = 0; p < m + 1; p++) {
				if (p == m) {
					cout << "Yes" << endl;
					return 0;
				}
				//				cout << b.at(i + p).substr(j, n) << "|" << a.at(i + p) << endl;
				if (b.at(i + p).substr(j, m) != a.at(p)) break;
			}
		}
	}
	cout << "No" << endl;
}
