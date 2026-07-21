#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
#include <iomanip>
#include <queue>
#include <cmath>
#include <math.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
using pll = pair<long long, long long>;
#define min(a, b) ((a) < (b) ? (a) : (b))



long long gcd(long long a, long long b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

double calculateDegree(double side, double B) {
	double radian = atan2(side, B);
	double degree = radian * (180.0 / 3.141592653589793238463);
	return degree;
}

int main() {
	int N;
	cin >> N;
	vector<long long> A(N);
	bool flag = false;
	long long tmp = 0;
	long long minusCount = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < 0) {
			++minusCount;
		}
		A.at(i) = abs(tmp);
	}

	if (minusCount % 2 != 0) flag = true;
	long long res = 0;
	for (int i = 0; i < N; i++) {
		res += abs(A.at(i));
	}
	if (flag) {
		sort(A.begin(), A.end());
		res -= A.at(0) * 2;
	}

	cout << res << endl;
}
