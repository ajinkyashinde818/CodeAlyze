#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<chrono>
#include<random>
#include<unordered_set>
using namespace std;
typedef long long int llint;
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
const int mod=1000000007;
const int big=1e9-10;
const llint red=0xE869120;
const llint pro=1002001;
const long double pai=3.141592653589793238462643383279;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
class UF{
public:
	vector<int>go;
	UF(int in){go.res(in);for(int i=0;i<in;i++){go[i]=i;}}
	int find_uf(int a){
		if(go[a]==a){return a;}
		return go[a]=find_uf(go[a]);
	}
	void uni_uf(int a,int b){go[find_uf(a)]=find_uf(b);}
};
int main(void){
	int all=0,n,i,q,w,ans=0;cin>>n;
	vector<int>mot(n+1);
	vector<int>at(n+1);
	vector<pair<int,int>> sor;//最初数,後すう
	for(i=0;i<n;i++){cin>>mot[i];all^=mot[i];}
	mot[n]=all;
	all=0;
	for(i=0;i<n;i++){cin>>at[i];all^=at[i];if(mot[i]==at[i]){continue;}sor.pub(mp(mot[i],at[i]));}
	at[n]=all;sor.pub(mp(mot[n],at[n]));//取り残し
	sort(sor.begin(),sor.end());
	sort(mot.begin(),mot.end());
	sort(at.begin(),at.end());
	if(mot!=at){cout<<"-1"<<endl;return 0;}
	UF ren(sor.size());
	for(i=1;i<sor.size();i++){
		if(sor[i-1].fir==sor[i].fir){ren.uni_uf(i,i-1);}
	}
	for(i=0;i<sor.size();i++){
		q=lower_bound(sor.begin(),sor.end(),mp(sor[i].sec,-1))-sor.begin();
		ren.uni_uf(q,i);
	}
	vector<int> kaz(sor.size());
	for(i=0;i<sor.size();i++){kaz[i]=ren.find_uf(i);}
	sort(kaz.begin(),kaz.end());
	ans=kaz.size();
	auto itr=unique(kaz.begin(),kaz.end());
	cout<<ans+(itr-kaz.begin())-2<<endl;
	return 0;
}
