#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	string s;
	cin >> n >> s;
	vector<bool> isL(2 * n);
	isL[0] = true;
	for(int i = 1; i < s.length() - 1; i++){
		if(s[i] == s[i - 1]){
			isL[i] = !isL[i - 1];
		} else {
			isL[i] = isL[i - 1];
		}
	}
	long long int lnum[200001] = {};
	long long int rnum[200001] = {};
	rnum[s.length() - 1] = 1;
	for(int i = s.length() - 2; i >= 0; i--){
		rnum[i] = rnum[i + 1];
		lnum[i] = lnum[i + 1];
		if(!isL[i]) rnum[i]++;
		else lnum[i]++;
	}
	if(rnum[0] != lnum[0] || s[0] == 'W' || s[s.length() - 1] == 'W'){
		cout << 0 << endl;
		return 0;
	}

	long long int ans = 1;
	for(int i = s.length() - 2; i >= 0; i--){
		if(!isL[i]) continue;
		ans = (ans * max((long long int)0, rnum[i] - lnum[i + 1])) % mod;
		// cout << i << " " << ans << endl;
	}

	for(int i = 1; i <= n; i++){
		ans = (ans * i) % mod;
	}
	cout << ans << endl;
}
