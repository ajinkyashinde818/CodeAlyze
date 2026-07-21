#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define ll long long
#define INF (1 << 30)
#define INFLL (1LL << 60)

#define FOR(i,a,b) for(ll i = (a);i<(b);i++)
#define REP(i,a) FOR(i,0,(a))
#define MP make_pair

int n, m;
bool img1[51][51] = {}, img2[51][51] = {};

bool solve(){
	for(int sx = 0;sx < n;sx++){
		for(int sy = 0;sy < n;sy++){
			bool flag = true;
			for(int px = 0;px < m;px++){
				for(int py = 0;py < m;py++){
					if(sx + px >= n || sy + py >= n) {
						flag = false;
						continue;
					}
					if(img1[sx+px][sy+py] != img2[px][py]) flag = false;
				}
			}
			if(flag) return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	string str;
	for(int i = 0;i < n;i++){
		cin >> str;
		for(int j = 0;j < str.size();j++){
			if(str[j] == '#') img1[j][i] = true;
			else img1[j][i] = false;
		}
	}

	for(int i = 0;i < m;i++){
		cin >> str;
		for(int j = 0;j < str.size();j++){
			if(str[j] == '#') img2[j][i] = true;
			else img2[j][i] = false;
		}
	}

	if(solve()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
