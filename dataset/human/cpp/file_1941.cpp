//Let's join Kaede Takagaki Fan Club !!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

struct dat {
	int cnt1;
	ll sum, sum1, sum2;
	//reverseする
	void rv(){
		swap(sum1, sum2);
	}
};

struct node{
	node *l, *r, *p;
	int id, rev;
	dat D, L, S;
	priority_queue<P>ins, del;
	
	node(int i, int c, int w) : l(0), r(0), p(0), id(i), rev(0){
		D = S = {c, w, w, w};
		L = {0, 0, 0, 0};
	}
};

inline bool is_root(node *n){
	return n -> p == NULL || n -> p -> l != n && n -> p -> r != n;
}

inline bool left(node *n){
	return n == n -> p -> l;
}

//遅延評価
//push(n)を走らせた後にはn->l と n->r の値は正しく計算されている必要あり
inline void push(node *n){
	if(n->rev){
		swap(n->l, n->r);
		if(n->l){
			n->l->rev ^= 1;
			n->l->D.rv();
		}
		if(n->r){
			n->r->rev ^= 1;
			n->r->D.rv();
		}
		n->rev = 0;
	}
}

//値の再計算
inline void update(node *n){
	//最初に遅延評価
	push(n);
	
	n->D.cnt1 = (n->l?n->l->D.cnt1:0) + (n->r?n->r->D.cnt1:0) + n->L.cnt1 + n->S.cnt1;
	n->D.sum = (n->l?n->l->D.sum:0) + (n->r?n->r->D.sum:0) + n->S.sum;
	n->D.sum1 = 0;
	if(n->l) n->D.sum1 += n->l->D.sum1;
	if(n->r) n->D.sum1 += n->r->D.sum1 + 1LL*(n->S.sum+(n->l?n->l->D.sum:0)) * n->r->D.cnt1;
	if(n->S.cnt1) n->D.sum1 += 1LL*(n->S.sum+(n->l?n->l->D.sum:0));
	n->D.sum1 += n->L.sum1 + 1LL*(n->S.sum+(n->l?n->l->D.sum:0)) * n->L.cnt1;
	
	n->D.sum2 = 0;
	if(n->l) n->D.sum2 += n->l->D.sum2 + 1LL*(n->S.sum+(n->r?n->r->D.sum:0)) * n->l->D.cnt1;
	if(n->r) n->D.sum2 += n->r->D.sum2;
	if(n->S.cnt1) n->D.sum2 += 1LL*(n->S.sum+(n->r?n->r->D.sum:0));
	n->D.sum2 += n->L.sum1 + 1LL*(n->S.sum+(n->r?n->r->D.sum:0)) * n->L.cnt1;
}
inline void connect(node *n, node *p, bool l){
	(l ? p -> l : p -> r) = n;
	if(n) n -> p = p;
}
//rotateが呼ばれる前には関与しているノードの遅延評価をする必要がある
inline void rotate(node *n){
	node *p = n -> p, *g = p -> p;
	bool l = left(n);
	connect(l ? n -> r : n -> l, p, l);
	bool ex = 0;
	if(!is_root(p)) connect(n, g, left(p));
	else{
		//light edgeを繋ぎ変える
		if(g){
			g->del.push(mp(p->D.cnt1, p->id));
			g->ins.push(mp(p->D.cnt1, n->id));
		}
		n -> p = g;
	}
	connect(p, n, !l);
	update(p), update(n);
}
inline void splay(node *n){
    if(is_root(n)){
        update(n);
        return;
    }
	while(!is_root(n)){
		node *p = n -> p, *g = p -> p;
		//関与する頂点群の遅延評価をする
		if(!is_root(p)) push(g);
		push(p), push(n);
		if(!is_root(p)) rotate(left(n) ^ left(p) ? n : p);
		rotate(n);
	}
}
//返り値はnじゃないよ
//部分木クエリの時は適切に更新
inline node* expose(node *n){
	node *last = NULL;
	for(node *m = n; m; m = m -> p){
		splay(m);
		if(m->r) {
			m->L.cnt1 += m->r->D.cnt1;
			m->L.sum1 += m->r->D.sum1;
			m->L.sum2 += m->r->D.sum1;
			m->ins.push(mp(m->r->D.cnt1, m->r->id));
		}
		m -> r = last;
		if(m->r) {
			m->L.cnt1 -= m->r->D.cnt1;
			m->L.sum1 -= m->r->D.sum1;
			m->L.sum2 -= m->r->D.sum1;
			m->del.push(mp(m->r->D.cnt1, m->r->id));
 		}
		update(m);
		last = m;
	}
	splay(n);
	return last;
}
//部分木クエリの時は適切に更新
inline void link(node *m, node *n){
	expose(m), expose(n);
	m -> p = n;
	n->L.cnt1 += m->D.cnt1;
	n->L.sum1 += m->D.sum1;
	n->L.sum2 += m->D.sum1;
	n->ins.push(mp(m->D.cnt1, m->id));
	update(n);
}
inline node* find_root(node *n){
	if(!n) return (node*)NULL;
	while(1){
		push(n);
		if(n->r) n = n->r;
		else break;
	}
	return n;
}
inline node* cut(node *n){
	expose(n);
	node *ret = n->l;
	n -> l -> p = NULL;
	n -> l = NULL;
	update(n);
	return find_root(ret);
}
//nを根に持っていく
//updateは必要ない
inline void evert(node *n){
	expose(n);
	n->rev ^= 1;
	n->D.rv();
}
const int MAXN = 400005;
node *V[MAXN];

int find(node *n, int sz){
	int lim = (sz+1)/2;
	while(1){
		push(n);
		if(n->r && n->r->D.cnt1 >= lim) n = n->r;
		else if(n->l && n->D.cnt1 - n->l->D.cnt1 < lim){
		    lim -= (n->D.cnt1-n->l->D.cnt1); n = n->l; 
		}
		else{
			while(n->del.size() && n->ins.size() && n->del.top() == n->ins.top()){
				n->del.pop();
				n->ins.pop();
			}
			if(n->ins.size() && n->ins.top().fi >= (sz+1)/2){
				lim = (sz+1)/2; n = V[n->ins.top().sc];
			}
			else return n->id;
		}
	}
}
int n, q;
ll sum;
int nxt = 200001;
int main(){
	scanf("%d",&n);
	repn(i, n) V[i] = new node(i, 0, 0);
	repn(i,n-1){
		int a,c; scanf("%d%d",&a,&c);
		V[nxt] = new node(nxt, 0, c);
		link(V[i+1], V[nxt]);
		link(V[nxt], V[a]);
		nxt++;
	}
	for(int k=1;k<=n;k++){
		evert(V[k]);
		V[k]->S.cnt1 ^= 1;
		update(V[k]);
		int c = find(V[k], V[k]->D.cnt1);
		evert(V[c]);
		printf("%lld\n", V[c]->D.sum1);
	}
}
