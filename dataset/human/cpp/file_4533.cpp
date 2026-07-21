#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 10e15+9
#define EPS 1e-10
#define MAX_N 100100
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

double t, d, ta, tb, da, db;

int main(){
	cin >> t >> d >> ta >> tb >> da >> db;
	double ans = INF;
	for (int i = 0; i < d; i += da){
		for (int j = 0; j + i <= d; j += db){
			ans = min(ans, abs(t - (ta*(double)i + tb*(double)j) / ((double)(i + j))));
		}
	}
	cout << ans << endl;
}
