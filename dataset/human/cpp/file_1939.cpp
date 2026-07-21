#include<cstdio>
#include<vector>
#include<set>
#include<utility>
#include<stack>
#include<cassert>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

const int MN=200200;
const int LOG_MN=19;

int N;
vector<int> G[MN];//only edges to leaf
vector<int> cost[MN];

int par[MN][LOG_MN];
long long dis[MN];
int dep[MN];

int pre[MN],pos[MN];

int c=1;
long long d=0;
int dep_=0;
stack<int> st;
bool flg[MN];
void dfs_(){
	st.push(0);
	dep[0]=0;
	dis[0]=0;
	while(!st.empty()){
		int cur=st.top();
		st.pop();
		if(!flg[cur]){
			flg[cur]=true;
			pre[cur]=c++;
			st.push(cur);
			for(int i=(int)G[cur].size()-1;i>=0;i--){
				int u=G[cur][i];
				dep[u]=dep[cur]+1;
				dis[u]=dis[cur]+cost[cur][i];
				st.push(u);
			}
		}else{
			pos[cur]=c;
		}
	}
}

int pre2[MN];
int pos2[MN];
long long dis2[MN];
int dep2[MN];

void dfs(int v){
	pre2[v]=c++;
	dis2[v]=d;
	::dep2[v]=dep_;
	dep_++;
	reverse(G[v].begin(),G[v].end());
	reverse(cost[v].begin(),cost[v].end());
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		int co=cost[v][i];
		d+=co;
		dfs(u);
		d-=co;
	}
	dep_--;
	pos2[v]=c;
}

void pre_lca(){
	for(int j=1;j<LOG_MN;j++){
		for(int i=0;i<N;i++){
			if(par[i][j-1]==-1) par[i][j]=-1;
			else par[i][j]=par[par[i][j-1]][j-1];
		}
	}
}

int get_lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;i<LOG_MN;i++){
		if((d>>i)&1){
			u=par[u][i];
		}
	}
	if(u==v) return v;
	for(int i=LOG_MN-1;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}

long long get_dis(int u,int v){
	int lca=get_lca(u,v);
	return dis[u]+dis[v]-dis[lca]*2;
}

set<P> se;
bool cand[MN];
set<P> cands;

struct BIT{
	int N;
	int dat[MN];
	void init(int N_){
		N=N_;
	}
	void add(int i){
		while(i<=N){
			dat[i]++;
			i+=(i&(-i));
		}
	}
	int sum(int i){
		int res=0;
		while(i>0){
			res+=dat[i];
			i-=(i&(-i));
		}
		return res;
	}
	int sum(int l,int r){
		return sum(r-1)-sum(l-1);
	}
};

BIT bit;

int cur_v;
long long cur_res;

int which_dir(int v,int t){
	if(v==t) return v;
	if(!(pre[v]<=pre[t]&&pre[t]<pos[v])) return par[v][0];
	int lb=0,ub=G[v].size();
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		int u=G[v][mid];
		if(pos[u]<=pre[t]){
			lb=mid;
		}else if(pre[u]<=pre[t]&&pre[t]<pos[u]){
			lb=mid;
			break;
		}else{
			ub=mid;
		}
	}
	return G[v][lb];
}

int get_sum(int v,int t){
	if(dep[v]<dep[t]){
		return bit.sum(pre[t],pos[t]);
	}
	return bit.sum(N)-bit.sum(pre[v],pos[v]);
}

struct Segtree{
	int N;
	P dat[524288];
	void init(int N_){
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<=N*2-1;i++){
			dat[i]=P(-1,-1);
		}
	}
	void update(int l,int r,P p,int k,int a,int b){
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r){
			dat[k]=max(dat[k],p);
			return;
		}
		update(l,r,p,k*2,a,(a+b)/2);
		update(l,r,p,k*2+1,(a+b)/2,b);
	}
	void update(int l,int r,P p){
		l--;r--;
		update(l,r,p,1,0,N);
	}
	P get(int id){
		id--;
		P res=P(-1,-1);
		id+=N;
		while(id>=1){
			res=max(res,dat[id]);
			id/=2;
		}
		return res;
	}
};

Segtree seg;

int get_nxt_v(int v,int t){
	if(pre[v]<pre[t]){
		P p=*(cands.lower_bound(P(pre[t],t)));
		return p.second;
	}
	//to ancestor
	P p=seg.get(pre[par[v][0]]);
	return p.second;
}

void add_cand(int v){
	cand[v]=true;
	cands.insert(P(pre[v],v));
	seg.update(pre[v],pos[v],P(pre[v],v));
}

void add_v(int v){
	P p=P(pre[v],v);
	set<P>::iterator it=se.lower_bound(p);
	if(it!=se.end()){
		int u=(*it).second;
		add_cand(get_lca(u,v));
	}
	if(it!=se.begin()){
		it--;
		int u=(*it).second;
		add_cand(get_lca(u,v));
	}
	se.insert(P(pre[v],v));
	add_cand(v);
	bit.add(pre[v]);
	if(cur_v==v) return;
	cur_res+=get_dis(v,cur_v);
//	printf("+=%d\n",get_dis(v,cur_v));
	int dir=which_dir(cur_v,v);
//	printf("v=%d,dir=%d",v,dir);
	int num=get_sum(cur_v,dir);
//	printf(" num=%d\n",num);
	if(num>(v+1)/2){
		int nv=get_nxt_v(cur_v,dir);
//		printf("nv=%d\n",nv);
		long long d=get_dis(nv,cur_v);
		cur_res-=d;
//		printf("-=%d\n",get_dis(nv,cur_v));
		cur_v=nv;
	}
}

void precalc(){
//	d=0;
//	dep_=0;
	assert(c==1);
	dfs_();
	c=1;
	seg.init(N);
	bit.init(N);
	pre_lca();
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N-1;i++){
		int p,d;
		scanf("%d%d",&p,&d);
		p--;
		G[p].push_back(i);
		cost[p].push_back(d);
		par[i][0]=p;
	}
	par[0][0]=-1;
	precalc();
	cur_v=0;
	cur_res=0;
	for(int i=0;i<N;i++){
		add_v(i);
		printf("%lld\n",cur_res);
	}
	return 0;
}
