#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<climits>
#include<bitset>
#include<bits/stdc++.h>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i,n) for(i=0;i<n;i++)
#define fin(ans) cout<<(ans)<<endl
#define INF INT_MAX
#define vvi vector<vector<int> >
#define vvc vector<vector<char> >
#define vvs vector<vector<string> >
#define P 1000000007
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const long long LLINF=1LL<<60;
//set<int>::iterator it;



int main(void){ios::sync_with_stdio(false);cin.tie(0);
//////////////////////////////////////////////////////
	
	int i,j,r,g,b,n,ans=0;
	cin>>r>>g>>b>>n;
	for(i=0;i<=9000;i++){
		for(j=0;j<=9000;j++){
			if((n-(i*r+j*g))%b==0&&(n-(i*r+j*g))/b>=0){
				ans++;
//				cout<<i<<j<<endl;
			}
		}
	}
	
	
	cout<<ans<<endl;
	
	
	
	
	
//////////////////////////////////////////////////////
return 0;}
