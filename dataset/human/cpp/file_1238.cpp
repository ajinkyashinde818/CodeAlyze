//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <iterator>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(v) reverse((v).begin(),(v).end())
#define ANS(ans) cout<<(ans)<<endl;
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
typedef vector<int> VI;
typedef pair<int, int> P;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)


int main() {
	VI v(3);
	int n;
	cin >> v[0] >> v[1] >> v[2] >> n;
	int cnt = 0;
	long long sum1 = 0,sum2=0;

	SORT(v);
	reverse(v.begin(), v.end());

	int r = n / v[0];
	for (int r = n/v[0]; r >= 0; r--) {
		sum1 = r*v[0];
		for (int g = (n - sum1) / v[1]; g >= 0; g--) {
			sum2 = sum1+g*v[1];
			if ((n - sum2) % v[2] == 0) {
				cnt++;
			}
		}
	}
	ANS(cnt);



	return 0;
}
