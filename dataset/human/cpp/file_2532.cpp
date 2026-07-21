#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

#define DEBUG(x) cout<<#x<<": "<<x<<endl

using namespace std;

int main(){

	long long N;

	cin >> N;

	long long ans = 0;
	int ok = 1;
	long long m = 1000000009;
	for(long long i = 0; i<N; i++){
		long long x;
		cin >> x;
		if(x < 0) ok *= -1;
		else if( x == 0) ok = 1;
		ans += abs(x);
		m = min(m, abs(x));
	}
	if(ok < 0){
		ans -= abs(m) * 2;
	}

	cout << ans << endl;

	return 0;
}
