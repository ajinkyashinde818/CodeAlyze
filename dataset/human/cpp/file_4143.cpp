#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<typename val_t, typename key_t>
struct FibonacciHeap{
	struct Node{
		val_t val;
		key_t key;
		int deg;
		Node *par, *ch, *l, *r;
		bool mark;
		Node(val_t val, key_t key):val(val), key(key), par(nullptr), ch(nullptr), l(this), r(this), mark(false), deg(0){}
	};
	vector<Node*> vr;
	Node *min_node;
	int sz;
	FibonacciHeap():sz(0), min_node(nullptr){}
	bool empty(){
		return sz==0;
	}
	void concat(Node *&s, Node *t){
		if(!t) return;
		if(!s){
			s=t;
			return;
		}
		s->r->l=t->l;
		t->l->r=s->r;
		s->r=t;
		t->l=s;
	}
	void delete_node(Node *t){
		t->l->r=t->r;
		t->r->l=t->l;
		t->l=t;
		t->r=t;
	}
	Node *push(val_t val, key_t key){
		sz++;
		Node *t=new Node(val, key);
		concat(min_node, t);
		if(!min_node || t->val<min_node->val) min_node=t;
		return t;
	}
	void link(Node *t, Node *c){
		t->deg++;
		delete_node(c);
		c->par=t;
		concat(c, t->ch);
		if(!t->ch) t->ch=c;
	}
	pair<val_t, key_t> pop(){
		sz--;
		pair<val_t, key_t> ret=make_pair(min_node->val, min_node->key);
		auto y=(min_node->r==min_node)?nullptr:min_node->r;
		delete_node(min_node);
		auto x=min_node->ch;
		if(x) x->par=nullptr;
		concat(x, y);
		min_node=nullptr;
		if(!x){
			return ret;
		}
		auto x1=x;
		do{
			x1->par=nullptr;
			if(!min_node || x1->val<min_node->val) min_node=x1;
			x1=x1->r;
		}while(x1!=x);
		x1=min_node;
		int last=-1;
		do{
			auto xr=x1->r;
			while(x1->deg<vr.size() && vr[x1->deg]){
				auto x2=vr[x1->deg];
				vr[x1->deg]=nullptr;
				if(x2==min_node || x1->val>x2->val){
					swap(x1, x2);
				}
				link(x1, x2);
			}
			if(x1->deg>=vr.size()) vr.resize(x1->deg+1);
			vr[x1->deg]=x1;
			last=max(last, x1->deg);
			x1=xr;
		}while(x1!=min_node);
		for(int i=0; i<=last; i++) vr[i]=nullptr;
		return ret;
	}
	void decrease(Node *t, val_t d){//t->val=d
		t->val=d;
		if(!t->par){
			if(!min_node || t->val<min_node->val) min_node=t;
			return;
		}
		if(t->par->val<=d) return;
		while(t->par){
			auto tp=t->par;
			t->par->deg--;
			t->par->ch=((t->r==t)?nullptr:t->r);
			delete_node(t);
			t->par=nullptr;
			concat(min_node, t);
			if(!min_node || t->val<min_node->val) min_node=t;
			if(!tp->mark){
				tp->mark=1;
				break;
			}
			t=tp;
		}
	}
};
int main()
{
	double x[1010], y[1010], r[1010];
	cin>>x[0]>>y[0]>>x[1]>>y[1];
	r[0]=0, r[1]=0;
	int n; cin>>n;
	for(int i=2; i<=n+1; i++) cin>>x[i]>>y[i]>>r[i];
	double d[1010][1010];
	for(int i=0; i<n+2; i++){
		d[i][i]=0;
		for(int j=0; j<i; j++){
			double l=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			d[i][j]=d[j][i]=max(0.0, l-(r[i]+r[j]));
		}
	}
	FibonacciHeap<double, int> que;
	using node=FibonacciHeap<double, int>::Node;
	vector<node*> v(n+2);
	double dist[1010];
	fill(dist, dist+n+2, 1e10);
	dist[0]=0;
	v[0]=que.push(0, 0);
	while(!que.empty()){
		auto p=que.pop();
		int x=p.second;
		for(int y=0; y<n+2; y++){
			if(dist[y]>dist[x]+d[x][y]){
				dist[y]=dist[x]+d[x][y];
				if(!v[y]) v[y]=que.push(dist[y], y);
				else que.decrease(v[y], dist[y]);
			}
		}
	}
	printf("%.10lf\n", dist[1]);
	return 0;
}
