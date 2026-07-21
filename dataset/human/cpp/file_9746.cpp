/*
ЗАПУСКАЕМ 
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░ 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
const string FILENAME = "input";
const int Mod = 1000000007;
const int MAXN = 100228;



int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}


int sum(int a, int b) {
	return (a + b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int n;
int st[MAXN];
int fact[MAXN];


int cnk(int a, int b) {
	return mul(fact[a], mul(powm(fact[b], Mod - 2), powm(fact[a - b], Mod - 2)));
}


int pref[MAXN];
map<char, int> cnt;

int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   // read(FILENAME);
	cin >> n;
   	string s;
   	cin >> s;
   	for (int i = 0; i < n; i++) {
   		cnt[s[i]]++;
   	}
   	int res = 1;
   	for (auto x: cnt) {
   		res = mul(res, x.second + 1);
   	}
   	res--;
   	if (res < 0) {
   		res += Mod;
   	}
   	cout << res << '\n';
 	return 0; 
}
