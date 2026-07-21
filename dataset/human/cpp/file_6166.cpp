#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	int n; ll c;
	ll X, V;
	cin >> n >> c;
	int i;
	ll x[100000], v[100000];
	ll score1[100000], score2[100000],score3[100000],score4[100000];
	for (i = 0; i < n; i++) {
		cin >> X >> V;
		x[i] = X; v[i] = V;
	}
	score1[0] = v[0] - x[0];
	score2[0] = v[n - 1] - (c - x[n - 1]);
	score3[0] = v[0] - 2*x[0];
	score4[0] = v[n - 1] - 2*(c - x[n - 1]);
	ll sushi1[100000], sushi2[100000], sushi3[100000], sushi4[100000];
	sushi1[0] = max((ll)0, score1[0]);
	sushi2[0] = max((ll)0, score2[0]);
	sushi3[0] = max((ll)0, score3[0]);
	sushi4[0] = max((ll)0, score4[0]);
	for (i = 1; i < n; i++) {
		score1[i] = score1[i-1]+v[i] - (x[i]-x[i-1]);
		score2[i] = score2[i-1]+v[n - 1 - i] - (x[n-i]-x[n - 1 - i]);
		score3[i] = score3[i - 1] + v[i] - 2*(x[i] - x[i - 1]);
		score4[i] = score4[i-1] + v[n - 1 - i] - 2*(x[n - i] - x[n - 1 - i]);
		sushi1[i] = max(sushi1[i - 1], score1[i]);
		sushi2[i] = max(sushi2[i - 1], score2[i]);
		sushi3[i] = max(sushi3[i - 1], score3[i]);
		sushi4[i] = max(sushi4[i - 1], score4[i]);
	}
	ll out = 0;
	for (i = 0; i < n-1; i++) {
		out = max(out, sushi1[i] + sushi4[n - 2 - i]);
		out = max(out, sushi2[i] + sushi3[n - 2 - i]);
	}
	out = max(out, sushi1[n - 1]);
	out = max(out, sushi2[n - 1]);
	cout << out << endl;
	return 0;
}
