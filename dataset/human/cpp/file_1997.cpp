#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include<bitset>
#include<string>
#include <deque>
#include<queue>
#include <iomanip>
#include<map>
#include <random>
#include<type_traits>
#include<stack>
#include <sstream> 
#include <limits>
#include <numeric>
#include<string.h>
using namespace std;
#define ll long long int
#define all(v) begin(v), end(v)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
//typedef vector<int> V;
//typedef vector<VV> VVV;



int main() {
	ll sum=0,a,n, count1 = 0, min = 1000000005;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 0)count1++;
		if (abs(a) < min)min = abs(a);
		sum += abs(a);
	}
	if (count1 % 2 == 0) {
		cout << sum << endl;
	}
	else {
		cout << sum - 2 * min << endl;
	}
	return 0;
}
