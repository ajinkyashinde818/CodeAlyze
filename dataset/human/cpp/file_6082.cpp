#include <bits/stdc++.h>
#include <iomanip>
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PLDLD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VB;
 
#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define endl "\n"
 
const LD eps=1e-10;
const long long INFLL=(LL)(1e9)*(LL)(1e9);
const int INF=1e9;
 
template<class T>
void chmin(T& a, const T b)
{
	if(a>b)
		a=b;
}
template<class T>
void chmax(T& a, const T b)
{
	if(a<b)
		a=b;
}
 
const LL pow(const LL p, const LL q)
{
	LL t=1;
	for(int i=0;i<q;i++)
		t*=p;
	return t;
}

template <typename T>
struct has_iter
{
	private:
		template <typename U>
		static constexpr true_type check(typename U::iterator*);
		template <typename U>
		static constexpr false_type check(...);

	public:
		static constexpr bool value = decltype(check<T>(nullptr))::value;
};


template<typename T, typename U = typename T::iterator>
void print(const T& container)
{
		auto&& first=begin(container), last=end(container);
		auto&& back=prev(last);
		for(auto e=first; e!=last; e=next(e))
			cout<<*e<<" \n"[e==back];
}


extern void* enabler;
template<typename Head, typename enable_if<!has_iter<Head>::value>::type*& = enabler>
void print(const Head& head)
{
	cout<<head<<endl;
}

template<> void print<string>(const string& container)
{
	cout<<container<<endl;
}

template<typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail)
{
	cout<<head<<" ";
	print(tail...);
}

void io_speedup()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec)
{
	for(T& x: vec) is >> x;
	return is;
}


template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p)
{
	os<<'('<<p.first<<", "<<p.second<<')';
	return os;
}

template<typename T>
vector<T> read(int n)
{
	vector<T> t(n);
	cin>>t;
	return t;
}

template<typename T>
T read()
{
	T t;
	cin>>t;
	return t;
}

template<typename Head, typename... Tail>
struct vector_demensions
{
	using type=vector<typename vector_demensions<Tail...>::type>;
};

template<typename Head>
struct vector_demensions<Head> { using type=Head; };

template<typename T>
vector<T> make_vectors(int size, T val)
{
	return vector<T>(size, val);
}

template<typename T=int, typename... Args>
auto make_vectors(int size, Args... tail)
	-> typename vector_demensions<Args..., T>::type
{
	auto val=make_vectors<T>(forward<Args>(tail)...);
	return vector<decltype(val)>(size, val);
}


template<class Monoid>
struct SegmentTree
{
	using M = Monoid;
	using T = typename M::type;

	const int SIZE;
	int tree_size, leaf_number;
	vector<T> node;
	
	SegmentTree(const vector<T> &ary);
	
	const int child_l(const int k) const
	{
		return k*2+1;
	}
	const int child_r(const int k) const
	{
		return k*2+2;
	}
	const int parent(const int k) const
	{
		return (k-1)/2;
	}
	const int least_square(const int k) const
	{
		if(k==0) return 0;
		int tmp=k-1;
		for(int i=1; 64>i; i<<=1)
			tmp |= (tmp >> i);
		return tmp+1;
	}
	
	const T init(const int k);
	const void update(const int k, const T x);
	const T fold(const int a, const int b, const int k, const int l, const int r) const;
	const T fold(const int a,const int b) const
	{
		return fold(a, b, 0, 0, leaf_number);
	}
	
	const void print() const
	{
		for(int i=0;i<tree_size;i++)
			cout<<node[i]<<" \n"[i==tree_size-1];
	}
};

template<class M>
SegmentTree<M>::SegmentTree(const vector<T> &ary):SIZE(ary.size())
{
	tree_size=SIZE;
	leaf_number=least_square(tree_size);
	tree_size=leaf_number*2;
	node=vector<T>(tree_size);
	tree_size--;
	
	for(int i=0;i<leaf_number;i++)
		if(i<SIZE)
			node[i+leaf_number-1]=ary[i];
		else
			node[i+leaf_number-1]=M::id();
				
	init(0);
}
	
	
template<class M>
const typename SegmentTree<M>::T SegmentTree<M>::init(const int k)
{
	if(k>=leaf_number-1) return node[k];
	return node[k]=M::op(init(child_l(k)),init(child_r(k)));
}
	
template<class M>
const void SegmentTree<M>::update(const int k, const T x)
{
	int tmp = k+leaf_number-1;
	node[tmp]=x;
	while(tmp > 0)
	{
		tmp=parent(tmp);
		node[tmp]=M::op(node[child_l(tmp)], node[child_r(tmp)]);
	}
}
	
template<class M>
const typename SegmentTree<M>::T SegmentTree<M>::fold(const int a, const int b, const int k, const int l, const int r) const
{
	if(r <= a || b <= l)
		return M::id();  //[a,b)と[l,r)が交わらない
	if(a <= l && r <= b) 
		return node[k];    //[a,b)が[l,r)を含む
	
	return M::op(fold(a,b,child_l(k),l,(l+r)/2), fold(a,b,child_r(k),(l+r)/2, r));
}

template <typename T>
struct MinMonoid 
{
	using type = T;
	static constexpr T id() { return numeric_limits<T>::max(); }
	static T op(const T &a, const T &b) { return min(a, b); }
};

template <typename T>
struct MaxMonoid 
{
	using type = T;
	static constexpr T id() { return numeric_limits<T>::min()/10; }
	static T op(const T &a, const T &b) { return max(a, b); }
};

template <typename T>
struct AddMonoid 
{
	using type = T;
	static constexpr T id() { return 0; }
	static T op(const T &a, const T &b) { return a + b; }
};

template <typename T>
struct MultMonoid 
{
	using type = T;
	static constexpr T id() { return 1; }
	static T op(const T &a, const T &b) { return a * b; }
};

template <typename T>
using RMQ = SegmentTree<MinMonoid<T>>;

template <typename T>
using RSM = SegmentTree<AddMonoid<T>>;

int main()
{
	int n;
	LL c;
	cin>>n>>c;
	VLL x(n*2+3),v(n*2+3);
	x[n+1]=c;v[n+1]=0;
	x[n*2+2]=c*2;v[n*2+2]=0;
	REP(i,n)
	{
		LL a,b;
		cin>>a>>b;
		x[i+1]=a;
		v[i+1]=b;
		x[n+i+2]=c+a;
		v[n+i+2]=b;
	}
	VLL ary(n*2+3);
	LL ans=0;
	LL cal=0;
	REP(i,n)
	{
		cal-=x[n+1+i+1]-x[n+1+i];
		cal+=v[n+1+i+1];
		ary[n+1+i+1]=cal;
		chmax(ans, cal);
	}
	cal=0;
	REP(i,n)
	{
		cal-=x[n+1-i]-x[n+1-i-1];
		cal+=v[n+1-i-1];
		ary[n+1-i-1]=cal;
		chmax(ans, cal);
	}

	/*print(x);
	print(v);
	print(ary);
	print(ans);*/
	SegmentTree<MaxMonoid<LL>> tree(ary);
	REP(i,n)
	{
		LL tmp=tree.fold(i+2,n+1)-(x[n+1+i+1]-x[n+1]) + ary[n+1+i+1];
		chmax(ans,tmp);
	}
	REP(i,n)
	{
		LL tmp=tree.fold(n+2,n+1+i+1)-(x[n+1]-x[i+1]) + ary[i+1];
		chmax(ans,tmp);
	}
	print(ans);
}
