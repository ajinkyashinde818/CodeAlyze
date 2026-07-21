#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
//cout<<setprecision(20)
const llint mod=987654323;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
int LBI(vector<lldo>&ar,lldo in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
int UBI(vector<lldo>&ar,lldo in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	llint n,c,i,ans=0;cin>>n>>c;
	vector<llint>x(n);
	vector<llint>v(n);
	for(i=0;i<n;i++){cin>>x[i]>>v[i];}
	vector<llint>zugo(n);//時計周り,行ったきり
	vector<llint>hago(n);
	llint gen=0,mae=0,wa=0;
	for(i=0;i<n;i++){
		wa+=v[i];wa-=x[i]-mae;
		maxeq(gen,wa);
		maxeq(zugo[i],gen);
		mae=x[i];
	}
	gen=0,mae=c,wa=0;
	for(i=n-1;i>=0;i--){
		wa+=v[i];wa-=mae-x[i];
		maxeq(gen,wa);
		maxeq(hago[i],gen);
		mae=x[i];
	}
	gen=0,mae=0,wa=0;
	for(i=0;i<n;i++){
		maxeq(ans,gen+hago[i]);
		wa+=v[i];wa-=(x[i]-mae)*2;
		maxeq(gen,wa);
		maxeq(zugo[i],gen);
		mae=x[i];
	}
	gen=0,mae=c,wa=0;
	for(i=n-1;i>=0;i--){
		maxeq(ans,gen+zugo[i]);
		wa+=v[i];wa-=(mae-x[i])*2;
		maxeq(gen,wa);
		maxeq(hago[i],gen);
		mae=x[i];
	}
	cout<<ans<<endl;
	return 0;
}
