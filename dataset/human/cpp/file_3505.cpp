#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(char ch) {
	return string("'")+ch+string("'");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <class InputIterator>
string to_string (InputIterator first, InputIterator last) {
	bool start = true;
	string res = "{";
	while (first!=last) {
		if (!start) {
			res += ", ";
		}
		start = false;
		res += to_string(*first);
		++first;
	}
	res += "}";
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x){
	input>>x.F>>x.S;
	return input;
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x){
	for(auto& i:x)
		input>>i;
	return input;
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif



const int mod=1e9+7;

int mul(int a,int b)
{
	return (a*1ll*b)%mod;
	}
	
void add(int &a,int b)
{
	a+=b;
	if(a>=mod)a-=mod;
	}
int powz(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=mul(res,a);
		b/=2;
		a=mul(a,a);
		}
	return res;
	}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=300005;

void solve()
{  
int n;
cin>>n;
vi a(n);
cin>>a;
int cnt=0;
for(int i=0;i<n;i++)if(a[i]<0)cnt++;
for(auto &i:a)i=abs(i);
sort(all(a));
if(cnt&1)
{
	cout<<accumulate(all(a),0ll)-2*a[0];
	}
else cout<<accumulate(all(a),0ll);
} 
	
	
   
	
	

signed main()
{   
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc=1;
	//cin>>tc;
    for(int i=0;i<tc;i++)
	{
		//cout<<"Case #"<<i+1<<": "; 
        solve();
		}
	
	}
