#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<math.h>
#include<numeric>
#include<cassert>
#include<random>
#include<deque>
#include<chrono>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
const ll E=1e18+7;
#define F first
#define S second
#define MK make_pair
const ll MOD=1000000007;




int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            char b;
            cin>>b;
            a[i].push_back((b=='#'?1:0));
        }
    }
    vector<vector<ll>> b(m);
    for(int i=0;i<m;i++){
        for(int t=0;t<m;t++){
            char c;
            cin>>c;
            b[i].push_back((c=='#'?1:0));
        }
    }
    bool judge=false;
    for(int i=0;i+m<=n;i++){
        for(int t=0;t+m<=n;t++){
            bool j=true;
            for(int x=0;x<m && j;x++){
                for(int y=0;y<m && j;y++){
                    if(b[x][y]!=a[x+i][y+t]){j=false;}
                }
            }
            if(j){judge=true;}
        }
    }
    cout<<(judge?"Yes":"No")<<endl;
    
    
    return 0;
}
