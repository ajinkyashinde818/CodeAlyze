#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<utility>
#include<functional>
#include<cfenv>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define vint vector<ll>
#define vvint vector<vint>
#define P pair<int,int>
#define INT_MAX 2147483647
using namespace std;
typedef long long ll;


int main(void) {
	int n, r; cin >> n >> r;
	if (n >= 10) {
		cout << r << endl;
	}
	else {
		cout << r+(100 * (10 - n)) << endl;
	}
	return 0;
}
