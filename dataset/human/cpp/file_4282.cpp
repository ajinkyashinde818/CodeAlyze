#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using ll = long long int;
using P = std::pair<int, int>;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

int a[100100],b[100100];
std::multiset<int> st;
int ufr[100100],ufp[100100],uff[100100];
std::vector<P> v,u;

void ufinit(int n){
	int i;
	for(i=0; i<=n; ++i){
		ufr[i] = 1;
		ufp[i] = i;
		uff[i] = (a[i]==a[n]);
	}
}

int ufind(int x){
	if(x==ufp[x]){
		return x;
	}
	return ufp[x] = ufind(ufp[x]);
}

void unionf(int x, int y){
	x = ufind(x); y = ufind(y);
	if(x==y){
		return;
	}
	if(ufr[x]<ufr[y]){
		std::swap(x,y);
	}
	ufr[x] += ufr[y];
	uff[x] |= uff[y];
	ufp[y] = x;
}

int main(void){
	int n,i,ans=0,cnt=0;
	std::cin >> n;
	for(i=0; i<n; ++i){
		std::cin >> a[i];
		u.push_back(P(a[i],i));
		a[n] ^= a[i];
	}
	u.push_back(P(a[n],n));
	for(i=0; i<n; ++i){
		std::cin >> b[i];
		if(a[i] != b[i] && a[i]==a[n]){
			++cnt;
		}
		v.push_back(P(b[i],i));
		b[n] ^= b[i];
	}
	v.push_back(P(b[n],n));
	std::sort(v.begin(),v.end());
	std::sort(u.begin(),u.end());
	for(i=0; i<=n; ++i){
		if(v[i].first != u[i].first){
			std::cout << "-1" << std::endl;
			return 0;
		}
	}
	v.clear(); u.clear();
	for(i=0; i<=n; ++i){
		if(a[i] == b[i]){
			continue;
		}
		u.push_back(P(a[i],i));
		v.push_back(P(b[i],i));
	}
	std::sort(v.begin(),v.end());
	std::sort(u.begin(),u.end());	
	ufinit(n);
	for(i=(v.l_ength()-1); i>=0; --i){
		unionf(u[i].second,v[i].second);
	}
	for(i=(v.l_ength()-1); i>0; --i){
		if(v[i].first==v[i-1].first){
			unionf(v[i].second,v[i-1].second);
			unionf(u[i].second,u[i-1].second);
		}
	}
	for(i=0; i<=n; ++i){
		// printf("%d: %d\n",i,ufind(i));
		if(a[i] == b[i]){
			continue;
		}
		++ans;
		if(ufind(i)==i){
			if(!uff[i]){
				++ans;
			}else if(ufind(n)==i){
				--ans;
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
