#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<list>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
#define REP(i,m,n) for(int i = (m); i < (n);i++)
#define rep(i,n) REP(i,0,n)

int main() {
	int n,m;
	cin >> n >> m;
	vector<char> a,b;
	rep(i,n)rep(j,n) {
		char c;
		cin >> c;
		a.push_back(c);
	}
	rep(i,m)rep(j,m) {
		char c;
		cin >> c;
		b.push_back(c);
	}
	rep(i,n-m+1) rep(j,n-m+1) {
		bool match = true;
		rep(di,m)rep(dj,m) {
			if(a.at((i+di)*n+(j+dj)) != b.at(di*m+dj)) {
				match = false;
				goto InnerBreak;
			}
		}
		InnerBreak:
		if(match) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}
