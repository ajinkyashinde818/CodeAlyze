#include "bits/stdc++.h"
using namespace std;
void __dump(int x){cerr << x;}
void __dump(long long x){cerr << x;}
void __dump(long double x){cerr << fixed << setprecision(3) << x;}
void __dump(char x){cerr << '\'' << x << '\'';}
void __dump(const string &x){cerr << '"' << x << '"';}
void __dump(const char *x){cerr << '"' << x << '"';}
void __dump(bool x){cerr << (x ? "true" : "false");}
void _dump(){cerr << "\n";}
template <typename T, typename U> void __dump(const pair<T, U> &x){cerr << '{'; __dump(x.first); cerr << ','; __dump(x.second); cerr << '}';}
template <typename T, typename U, typename V> void __dump(const tuple<T, U, V> &x){cerr << '{'; __dump(get<0>(x)); cerr << ',';  __dump(get<1>(x)); cerr << ',';  __dump(get<2>(x)); cerr << '}';}
template <typename T> void __dump(const T& x){int f=0; cerr << '{'; for(auto&i:x) cerr << (f++ ? "," : ""), __dump(i); cerr << "}";}
template <typename T, typename ... U> void _dump(T t, U ... u){__dump(t); if(sizeof...(u)) cerr << ", "; _dump(u...);}
#ifdef ilyes
	#define dump(x ...) cerr  <<  "|dumping| "  <<  # x  <<  "  =  ", _dump(x) 
#else
	#define dump(...) 1998
#endif
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define pii pair<int,int>
const int INF = 1e9;
const int N = -1;

struct Trie{
	map<char,Trie*> child; bool en = false; int h = 0;
	void addWord(const string& _word){
		Trie* cur = this;
		for(int i=0; i<=size(_word)-1; ++i){
			Trie* nxt = (*cur).child[_word[i]];
			if(!nxt){
				nxt = new Trie();
				(*nxt).h = (*cur).h + 1;
				(*cur).child[_word[i]] = nxt;
			}
			cur = nxt;
		}
		(*cur).en = true;
	}
	bool hasWord(const string& _word){
		Trie* cur = this;
		for(int i=0; i<=size(_word)-1; ++i){
			Trie* nxt = (*cur).child[_word[i]];
			if(!nxt) return false;
			cur = nxt;
		}
		return (*cur).en;
	}
	void explore(vector<int>& vect){
		if(size(child) == 1) vect.emplace_back(h);
		if(child['0'] != nullptr) (*child['0']).explore(vect);
		if(child['1'] != nullptr) (*child['1']).explore(vect);
	}
};

int n;
LL l;
Trie* root = new Trie();

int main(){ FAST
	cin >> n >> l;
	for(int i=1; i<=n; ++i){
		string ss; cin >> ss;
		(*root).addWord(ss);
	}
	
	vector<int> vect;
	(*root).explore(vect);
	// dump(vect);
	LL xr = 0;
	for(int hh: vect) if(l - hh >= 1) xr ^= (1LL << __builtin_ctzll(l - hh));

	if(xr > 0) cout << "Alice" << ln;
	else cout << "Bob" << ln;
}
