#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)
#define max(a,b) ((a) < (b) ? (b) : (a))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define AAA (1000000007)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;



ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a,ll b) {
	return a / gcd(a, b) * b;
}



int main() {
	int i, j, k;
	ll N, M, K;
	ll ans = 0;
	
	cin >> N >> M;
	if (N >= 10)cout << M;
	else
		cout << M + 100 * (10 - N);


	
	return 0;


}
