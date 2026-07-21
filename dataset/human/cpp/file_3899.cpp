//#include "IntMod.h"
//typedef IntMod<1000000007> MInt;

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define REP(i,a,n) for(int i = a; i < n; ++i)
#define REPM(i,n,a) for(int i = n - 1; i >= a; --i)
#define EPS 0.0001
#define INF 0x3FFFFFFF
#define INFD 1.0e+308
typedef long long LL;
typedef unsigned long long ULL;

int N;
double s_x, s_y, t_x, t_y;
double x[1002], y[1002], r[1002];
double mat[1002][1002];

void input() {
	cin >> s_x >> s_y >> t_x >> t_y >> N;
	REP(i, 1, N + 1) {
		cin >> x[i] >> y[i] >> r[i];
	}
	x[0] = s_x;
	y[0] = s_y;
	x[N + 1] = t_x;
	y[N + 1] = t_y;
}
void make_mat() {
	REP(i, 0, N + 2) {
		REP(j, 0, N + 2) {
			mat[i][j] = (i == j) ? INFD :
				max(0.0, sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i])) - (r[i] + r[j]));
		}
	}
}

bool ffixed[1002];
double dist[1002];
void dij() {
	REP(i, 0, N + 2) {
		dist[i] = INFD;
	}

	int curr = 0;
	dist[0] = 0;
	while(curr != N + 1){
		ffixed[curr] = true;
		REP(i, 0, N + 2) {
			if (ffixed[i] == false) {
				dist[i] = min(dist[i], dist[curr] + mat[curr][i]);
			}
		}

		int next = 0;
		double min = INFD;
		REP(i, 0, N + 2) {
			if (ffixed[i] == false && dist[i] < min) {
				next = i;
				min = dist[i];
			}
		}
		curr = next;
	}
	return;
}

int main() {
	input();
	make_mat();
	dij();
	printf("%.12f", dist[N + 1]);
	return 0;
}
