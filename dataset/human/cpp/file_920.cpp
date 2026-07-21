#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>

#include<stack>
#include<queue>
#include<time.h>
#include<set>
#include<map>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll mod = 998244353;



ll N, R, G, B,ans;
string S;

int main() {
	
	cin >>R>>G>>B>> N;

	FOR(i, 0, 3001) {
		FOR(j, 0, 3001) {
			if ((N - i * R - j * G) >= 0 && (N - i * R - j * G) % B == 0)ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}
