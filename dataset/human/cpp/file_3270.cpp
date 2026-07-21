#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <time.h>
#include <complex>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n;i>0;i--)
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define SORT(v) sort((v).begin(),(v).end())
#define TEMP(type,x,y) do {temp temp=x,x=y,y=temp}while(0)
const ll INF = (1LL << 50);

int main() {

	int N;
	cin >> N;

	int count_minus = 0;
	vector<ll>num(N);
	ll sum = 0;
	REP(i, N) {
		cin >> num[i];
		if (num[i] < 0) count_minus++;
		num[i] = abs(num[i]);
		sum += num[i];
	}

	
	if (count_minus % 2 == 0) {
		cout << sum << endl;
	}
	else {
		ll minimum = INF;
		REP(i, N) {
			minimum = min(minimum, num[i]);
		}

		cout << sum - 2 * minimum << endl;

	}

	return 0;

}
