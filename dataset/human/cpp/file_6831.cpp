#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int a[225816],b[225816],c[225816],d[225816];
P v[225816],u[225816];

int main(void){
	int n,i,j,l,r;
	std::cin >> n;
	for(i=0; i<n; ++i){
		std::cin >> a[i];
		++c[a[i]];
	}
	for(i=0; i<n; ++i){
		std::cin >> b[i];
		++d[b[i]];
	}
	for(i=1; i<=n; ++i){
		if(c[i]+d[i]>n){
			std::cout << "No" << std::endl;
			return 0;
		}
		u[i-1] = P(c[i]+d[i],i);
	}
	std::cout << "Yes" << std::endl;
	std::sort(u,u+n,std::greater<P>());
	l = 0; r = n-1;
	for(i=0; i<n; ++i){
		while(l<=r && c[u[i].second]){
			v[l].first = u[i].second;
			++l; --c[u[i].second]; --u[i].first;
		}
		while(l<=r && d[u[i].second]){
			v[r].second = u[i].second;
			--r; --d[u[i].second]; --u[i].first;
		}
		if(u[i].first){
			for(j=0; j<n; ++j){
				if(v[j].first == u[i].second || v[j].second == u[i].second ){
					continue;
				}
				if(v[j].first && d[u[i].second]){
					v[j].second = u[i].second;
					--d[u[i].second]; --u[i].first;
				}else if(v[j].second && c[u[i].second]){
					v[j].first = u[i].second;
					--c[u[i].second]; --u[i].first;
				}
			}
			break;
		}
	}
	l = 0; r = 0;
	for(i=0; i<n; ++i){
		while(c[u[i].second]){
			if(v[l].first){
				++l; continue;
			}
			v[l].first = u[i].second;
			++l; --c[u[i].second]; --u[i].first;
		}
		while(d[u[i].second]){
			if(v[r].second){
				++r; continue;
			}
			v[r].second = u[i].second;
			++r; --d[u[i].second]; --u[i].first;
		}
	}
	std::sort(v,v+n);
	for(i=0; i<n; ++i){
		std::cout << (i?" ":"") << v[i].second;
	}
	std::cout << std::endl;
	return 0;
}
