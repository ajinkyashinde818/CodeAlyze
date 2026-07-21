#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX/2
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };

void err() {
	cout << "No" << endl;
	exit(0);
}

int main() {
	int n;
	cin >> n;
	vector<int>check(101010,0);

	int k = 1;
	int c;
	while (1) {
		c = k*(k + 1) / 2;
		if (c >= 101010)break;
		else {
			check[c] = k;
		}
		k++;
	}

	if (check[n] == 0)err();
	cout << "Yes" << endl;


	int num = check[n] + 1;
	vector<vector<int>>s(num);

	cout << num << endl;

	int p = 1;
	rep(i,0,num) {
		rep(j, i + 1, num) {
			s[i].pb(p);
			s[j].pb(p);
			p++;
		}
	}

	rep(i, 0, num) {
		cout << num-1;
		rep(j, 0, num-1) {
			cout << " " <<s[i][j];
		}
		cout << endl;
	}
	

	return 0;
}
