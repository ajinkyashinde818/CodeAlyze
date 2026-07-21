//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
//struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
__attribute__((constructor))
void init(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(15);
}
// random_device rd;
// mt19937 mt(rd());
// #include <boost/numeric/interval.hpp>
// #include <boost/numeric/interval/io.hpp>
// #include <boost/intrusive/rbtree.hpp>
// #include <boost/dynamic_bitset.hpp>
// #include <boost/geometry.hpp>
// #include <boost/geometry/geometries/linestring.hpp>
// #include <boost/geometry/geometries/polygon.hpp>
// #include <boost/geometry/geometries/point_xy.hpp>
// #include <boost/math/tools/minima.hpp>
// using boost::math::tools::brent_find_minima;
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// typedef mp::number<mp::cpp_dec_float<256>> cdouble;
// typedef mp::cpp_int cint;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template<typename T=long long>using pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T=long long>using pbds_map=tree<T,T,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T=long long>using pqueue =__gnu_pbds::priority_queue<T, less<T>,rc_binomial_heap_tag>;
typedef long long lint;
typedef long long ll;
typedef long double ldouble;
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<double> dvec;
typedef vector<vector<double>> dmat;
typedef vector<vector<vector<double>>> dmat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef vector<vector<vector<string>>> smat3;
typedef vector<pair<lint,lint>> pvec;
typedef vector<vector<pair<lint,lint>>> pmat;
typedef vector<vector<vector<pair<lint,lint>>>> pmat3;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define irep(i) for(lint i = 0;; i++)
#define irep1(i) for(lint i = 1;; i++)
#define irep2(i) for(lint i = 2;; i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define PI 3.141592653589793
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"");if(i>INF/2)cout<<"INF";else cout<<i;f=1;}cout<<"\n";}while(0);
#define output2(v) for(auto j:v)output(j);
#define _output(v) do{bool f=0;rep(i,v.size()){cout<<(f?" ":"");if(v[i]>INF/2)cout<<"INF";else cout<<v[i];f=1;}cout<<"\n";}while(0)
#define _output2(v) rep(j,v.size()){_output(v[j]);}
#define input(a,n) lint n;cin>>n;vector<lint>a(n);rep(i,n)cin>>a[i];
#define SUM(v) accumulate(all(v),0LL)
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define LINF 9223372036854775807
#define MOD 998244353LL
#define endl "\n"
template<typename T=lint>T in(){return *istream_iterator<T>(cin);}
inline lint gcd(lint a,lint b){return b?gcd(b,a%b):a;}
template<typename T=lint>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<typename T=lint>inline T add(T a,T b){return a+b;}
template<typename T=lint>inline T minq(T a,T b){return min(a,b);}
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};



// template<typename T,typename E>
// struct RBST{
// 	struct node{
// 		int cnt=1,l=-1,r=-1;
// 		T key;E val;
// 		node(){}
// 		node(T key,E val):key(key),val(val){}
// 	};
// 	vector<node> v;
// 	RBST(){
// 	}
// 	int root=1;
// 	int count(int idx){return idx==-1?0:v[idx].cnt;}
// 	int update(int idx){
// 		if(idx!=-1)v[idx].cnt=1+count(v[idx].l)+count(v[idx].r);
// 		return idx;
// 	}
// 	private:
// 	inline int merge(int l,int r){
//         if(l==-1||r==-1)return l==-1?r:l;
//         if((unsigned long)count(v[l])>rnd()%(unsigned long)(count(v[l])+count(v[r]))){
//             v[l].r=merge(v[l].r,r);
//             return update(l);
//         }else{
//             v[r].l=merge(l,v[r].l);
//             return update(r);
//         }
//     }
// 	inline pair<int,int> split(int t,int k){
//         if(t==-1)return make_pair(-1,-1);
//         if(k<=count(v[t].l)){
//             auto s=split(v[t].l,k);
//             v[t].l=s.second;
//             return make_pair(s.first,update(t));
//         }else{
//             auto s=split(v[t].r,k-count(v[t].l)-1);
//             v[t].r=s.first;
//             return make_pair(update(t),s.second);
//         }
//     }
// 	inline unsigned long rnd() {
//         static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
//         unsigned long t=(x^(x<<11));
//         x=y; y=z; z=w;
//         return ( w=(w^(w>>19))^(t^(t>>8)) );
//     }
// };

template<typename E=lint,typename T=double>
vector<T> dij(vector<vector<pair<E,T>>> list,lint s){
    std::priority_queue<pair<T,E>,vector<pair<T,E>>,greater<pair<T,E>>>que;
    vector<T>diff(list.size(),INF);
    diff[s]=0;
    que.push(make_pair(T(),s));
    while(!que.empty()){
        auto d=que.top();
        que.pop();
        T x;E now;
        tie(x,now)=d;
        for(auto d2:list[now]){
            T sa;E to;
            tie(to,sa)=d2;
            if(chmin(diff[to],diff[now]+sa))que.emplace(diff[to],to);
        }
    }
    return diff;
}
int main(){
    lint xs,ys,xt,yt;
    cin>>xs>>ys>>xt>>yt;
    lint n;
    cin>>n;
    vec x(n),y(n),r(n);
    rep(i,n){
        cin>>x[i]>>y[i]>>r[i];
    }
    vector<vector<pair<lint,double>>> v(n+2);
    rep(i,n)rep(j,n){
        double tmp=max(0.,dist(x[i],y[i],x[j],y[j])-r[i]-r[j]);
        v[i].push_back(make_pair(j,tmp));
        v[j].push_back(make_pair(i,tmp));
    }
    rep(i,n){
        double tmp=max(0.,dist(xs,ys,x[i],y[i])-r[i]);
        v[n].push_back(make_pair(i,tmp));
    }
    rep(i,n){
        double tmp=max(0.,dist(xt,yt,x[i],y[i])-r[i]);
        v[i].push_back(make_pair(n+1,tmp));
    }
    v[n].push_back(make_pair(n+1,max(0.,dist(xs,ys,xt,yt))));
    cout<<dij<lint,double>(v,n)[n+1]<<endl;
}
