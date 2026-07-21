#include <bits/stdc++.h>
using namespace std;
/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __     _______    _______      
 * |\  \|\  \  |\  ___ \  |\  ___ \     
 * \ \  \/  /|_\ \   __/| \ \   __/|    
 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  
 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 
 *    \ \__\\ \__\\ \_______\\ \_______\
 *     \|__| \|__| \|_______| \|_______|
 */
const long long mod = 1000000007;

const int mxN = 100010;
pair<int,int> tree[mxN<<2];
long long L;
int sz;

long long getXOR(long long X) {
	if(!X) return 0;
	long long res = 1;
	while(!(X&1)) res <<= 1,X >>= 1;
	return res;
}

long long dfs(int v = 1,long long h = 0) {
	if(!tree[v].first && !tree[v].second) return 0;
	long long res = 0;
	if(tree[v].first) res ^= dfs(tree[v].first,h+1); else res ^= getXOR(L-h);
	if(tree[v].second) res ^= dfs(tree[v].second,h+1); else res ^= getXOR(L-h);
//	cerr<<v<<' '<<h<<' '<<res<<'\n';
	return res;
}

//void get(int x) {
//	vector<int> dp(x+2);
//	dp[1] = 1;
//	cerr<<"1 ";
//	for(int i = 2;i <= x;i++) {
//		set<int> to;
//		int cur = 0;
//		to.insert(cur);
//		for(int j = i-1;j >= 1;j--) {
//			cur ^= dp[j];
//			to.insert(cur);
//		}
//		while(to.count(dp[i])) dp[i]++;
//		cerr<<dp[i]<<' ';
//	}
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//	get(100);
	//	return 0;

	cerr<<getXOR(2)<<'\n';
	
	int N;
	string s;
	cin>>N>>L;
	sz = 1;
	for(int i = 0;i < N;i++) {
		cin>>s;
		int cur = 0;
		for(int j = 0;j < (int)s.size();j++) {
			auto & to = (s[j]=='0'?tree[cur].first:tree[cur].second);
			if(!to) to = sz++;
			cur = to;
		}
	}
	assert(sz <= mxN);
	cout<<(dfs(0)?"Alice":"Bob")<<'\n';
	return 0;
}
