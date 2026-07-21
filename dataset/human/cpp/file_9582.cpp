//#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N, M;
	cin >> N >> M;
	VVI A;
	A.resize(N, VI(N,0));
	for (int y = 0; y < N; y++) {
		string S;
		cin >> S;
		for (int x = 0; x < N; x++) {
			if (S[x] == '.')A[y][x] = 0;
			else A[y][x] = 1;
		}
	}
	VVI B;
	B.resize(M, VI(M, 0));
	for (int y = 0; y < M; y++) {
		string S;
		cin >> S;
		for (int x = 0; x < M; x++) {
			if (S[x] == '.')B[y][x] = 0;
			else B[y][x] = 1;
		}
	}
	for (int dy = 0; M - 1 + dy < N; dy++) {
		for (int dx = 0; M - 1 + dx < N; dx++) {
			bool flag = true;
			for (int x = 0; x < M; x++) {
				for (int y = 0; y < M; y++) {
					if (B[y][x] != A[y + dy][x + dx]) {
						flag = false;
						break;
					}
				}
				if (!flag)break;
			}
			if (flag) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}
