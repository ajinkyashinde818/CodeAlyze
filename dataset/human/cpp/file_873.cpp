//#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <vector>
#include <math.h>
#include <set>
#include <numeric>

using namespace std;

typedef pair<long long, long long> pl;

long long N, M, k, a, b, c, d, e, H, W,X;
long long A[200000] = {};
long long B[365][365] = {};
bool f;
bool ff;
string S, SS;
set <long long>sll;
pl buf;
vector <long long>vl;

struct ST
{
	long long total;
	long long aki;
	long long itta;
};

vector <ST> vst;
ST st;

int main() {

	cin >> a>>b>>c>>N;
	d = 0;

	for (int i = 0; i*a <= N; i++) {
		for (int j = 0; i*a + j*b <= N; j++) {
			if ((N - i*a - j*b) % c == 0) {
				d++;
			}
		}

	}

	cout << d<<endl;

	return 0;
}
