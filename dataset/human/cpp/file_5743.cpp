#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <cassert>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define int long long
class Trie {
public:
	struct Node {
		Node *next[2];
		int sub;
		int dep;
		Node() : sub(0),dep(0){
			for(int i = 0; i < 2; i++){
				next[i] = nullptr;
			}
		}
	};
	Node* root;
	Trie(){
		root = new Node();
	}
	//Trie木にxを加える
	void add(string& s) {
		Node *curr = root;
		for(int i = 0; i < (int)s.size(); i++){
			int y = s[i] - '0';
			if (!curr->next[y]) {
				curr->next[y] = new Node();
			}
			curr = curr->next[y];
			curr->dep = i+1;
		}
		curr->sub= 1;
	}
    //何らかのクエリ
	set<int> query(Node *curr) {
		if(curr->sub==1){
			set<int>st;
			return st;
		}
		set<int> s,t;	
		if(curr->next[0]){
			s = query(curr->next[0]);	
		}else{
			s.insert(curr->dep+1);
		}
		if(curr->next[1]){
			t = query(curr->next[1]);
		}else{
			t.insert(curr->dep+1);
		}
		if(s.size()>t.size()){
			swap(s,t);
		}
		for(auto x:s){
			if(t.count(x)){
				t.erase(x);
			}else{
				t.insert(x);
			}
		}
		return t;
	}
	set<int> query() {
		return query(root);
	}
};

void B(){
	cout << "Bob" << endl;	
}

void A(){
	cout << "Alice" << endl;	
}

signed main(){
	ll n,l;
	cin >> n >> l;
	Trie tr;
	rep(i,n){
		string s;
		cin >> s;
		tr.add(s);
	}
	set<int> res = tr.query();
	res.erase(l+1);
	set<ll,greater<ll> > a;
	for(auto x:res){
		a.insert(l-x+1);
	}
	// for(auto x:a){
	// 	cout << x << endl;
	// }
	bool flag = 1;
	while(!a.empty()){
		ll k = *(a.begin());
		if(k%2==1){
			if(k==1)break;
			a.erase(k);
			if(a.count(1)){
				a.erase(1);
			}else{
				a.insert(1);
			}
			continue;
		}
		ll p = 1;
		for(int i=0;i<60;i++){
			if(k%(p*2)==0){
				p*=2;
			}else{
				break;
			}
		}
		if(k==p){
			break;
		}else{
			a.erase(k);
			if(a.count(p)){
				a.erase(p);
			}else{
				a.insert(p);
			}
		}
	}
	if(a.size()!=0){
		A();
	}else{
		B();
	}
	return 0;
}
