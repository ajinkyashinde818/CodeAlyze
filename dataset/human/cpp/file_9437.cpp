#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

typedef long long ll;
using namespace std;
const ll INF = 1000000000000000000ll;
const ll MOD = 1000000007ll;

const double EPS = 1e-8;

int main()
{
	string A[50],B[50];

	ll N=0,M=0,cnt=0,ans=0;

	cin >> N >> M;

	for(ll i=0;i<N;i++){
		cin >> A[i];
	}

	for(ll i=0;i<M;i++){
		cin >> B[i];
	}

	for(ll i=0;i<=N-M;++i){
		for(ll j=0;j<=N-M;++j){
			for(ll k=0;k<M;k++){
				for(ll m=0;m<M;m++){
					if(A[i+k][j+m]==B[k][m])
						cnt++;
				}
			}
			if(cnt==M*M){
				ans=1;
			}
			cnt=0;
		}
	}

	cout << ((ans==1) ? "Yes" : "No");
	
	return 0;
}
