#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <random>

using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
bool LR[200000];
void Calc(){
	int N = rei()*2;
	string S = res();
	LR[0] = (S[0] == 'B');
	for(int i=1;i<N;i++){
		LR[i] = (S[i] != S[i-1]) ^ (!LR[i-1]);
	}
	long ans = 1;
	int c = 0;
	for(int i=0;i<N;i++){
		if(LR[i]){
			c++;
		}
		else{
			ans *= c;
			ans %= mod;
			c--;
			if(c == -1){
				cout << 0 << endl;
				return;
			}
		}
	}
	if(c != 0){
		cout << 0 << endl;
		return;
	}
	for(int i=1;i<=N/2;i++){
		ans *= i;
		ans %= mod;
	}
	cout << ans << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}
