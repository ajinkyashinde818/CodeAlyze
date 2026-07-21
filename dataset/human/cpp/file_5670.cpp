//By Ralif Rakhmatullin
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<valarray>
#include<iterator>
#include<list>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define S second
#define ld long double
#define F first
#define y1 LOL
#define ld long double
#define pb push_back
#define len length
#define sz size
#define beg begin
const ll INF = (ll)1e18 + 123;
const int inf=(int)2e9 + 123; 
const int mod=1e9+7;
using namespace std;
int n;
ll L;
int sz = 0;    
struct trie{
	int nx[2];	
	ll h;
	trie(){
		nx[1] = nx[0] = -1;
		h = 0;
	}
	trie(ll x){
		nx[0] = nx[1] = -1;
		h = x;
	}
};
ll ans = 0;
vector<trie> t;
void add(string s){
	int x = 0, pos = 0;
	while(pos < s.len()){
		int ch = s[pos] - '0';
		if(t[x].nx[ch] == -1){
			t[x].nx[ch] = ++ sz;
			trie y;
			t.pb(y);
		}
		t[t[x].nx[ch]].h = t[x].h + 1;
		pos ++;
		x = t[x].nx[ch];
	}
}
ll get(ll x){
	ll res = 1;
	while(x % 2 == 0){
		res *= 2;
		x /= 2;
	}
	return res;
}
void out(int v){
	int cnt = 0;
	for(int i = 0; i < 2; i ++){
		if(t[v].nx[i] > -1){	
			cnt ++;
			out(t[v].nx[i]);
		}
	}
	if(cnt == 1){
		ans = (ans ^ get(L - t[v].h));
	}
}
string s[100011];
int main(){
	unsigned int FOR;
 	asm("rdtsc" : "=A"(FOR));
  	srand(FOR);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	t.pb(trie());
	cin >> n >> L;
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		add(s[i]);
	}
	out(0);
	if(ans == 0)
		cout << "Bob";
	else
		cout << "Alice";
	return 0;
}
