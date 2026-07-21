#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define POWER9 1000000000
#define MOD POWER9+7
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359
LL a[200000];
LL wa[200000];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(9);

	int N;
	cin >> N;
	
	cin >> a[0];
	wa[0] = a[0];
	for(int i=1; i<N; i++){
		cin >> a[i];
		wa[i] = wa[i-1] + a[i];
	}
	LL ans = LL_MAX;
	for(int i=0; i<N-1; i++){
		ans = min(ans, abs(wa[N-1]-2*wa[i]));
	}
	cout << ans << endl;

	return 0;
}
