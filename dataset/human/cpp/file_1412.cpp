#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	int K = 0;
	while(K*(K-1)/2 < N) K++;
	if(K*(K-1)/2 != N) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n" << K << "\n";
	vector< vector<int> > sets(K);
	int cur = 1;
	for(int i = 0; i < K; i++) for(int j = i+1; j < K; j++) {
		sets[i].push_back(cur);
		sets[j].push_back(cur++);
	}
	for(int i = 0; i < K; i++) {
		cout << sets[i].size();
		ALL_THE(sets[i], it) cout << " " << *it;
		cout << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
