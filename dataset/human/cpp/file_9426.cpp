#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<array>
#include<cassert>
#include<list>
#include<experimental/any>
#include<cstring>
#include<cctype>
#include<ctime>
#include<cstdbool>
#include<cstdint>
#include<cstddef>
#include<set>
#include<unordered_set>
#include<bitset>

using namespace std;
using experimental::any;
 
#define SPEEDY cin.tie(0);ios::sync_with_stdio(false);
 
#define REP(i,n) for(int i=0;i<(n);i++)
#define ARREP(i,n,X) for(int i=0;i<(n);i++)cin>>X[i]
#define FOR(i,X,n) for(int i=(X);i<(n);i++)
#define EREP(i,n) for(int i=1;i<=n;i++)
#define BitFOR(N) REP(Bit,1<<(N))
 
#define MODE 0
#define DEB(X) if(MODE)cout<< #X <<": "<<X<<" ";
#define DEB2(X) if(MODE)cout<<X<<" ";
#define ARDEB(i,X) if(MODE)cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define TFDEB(f) if(MODE){(f)? cout<<"true ":cout<<"false ";}
#define FORDEB(n,X) if(MODE)for(int i=0;i<(n);i++)ARDEB(i,X)
#define END if(MODE)cout<<endl;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define ALL(X) X.begin(),X.end()
struct edge{int to,cost;};
//struct edge{int from,cost,to;};
struct P2{int x,y;};
#define BIT(Bit,n) bitset<n>(Bit)
#define Endl endl
 
const int MOD7=1000000007;
const int INF=100000000;
const int SET=1000;
 
int main(){
	int n,m;
	char s[55][55],t[55][55],dim=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	REP(i,n-m+1)REP(j,n-m+1){
		dim=0;
		for(int k=0;k<m;k++){
			int count=0;
			for(int l=0;l<m;l++){
				if(s[i+k][j+l]==t[k][l]){
					count++;
				}
			}
			if(count==m){
				dim++;
			}
		}
		if(dim==m){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
