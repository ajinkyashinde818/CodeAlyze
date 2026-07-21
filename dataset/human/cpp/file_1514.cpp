#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;cin>>n;
    rep(i,1000){
        int res=i*(i-1)/2;
        if(res==n){
            cout<<"Yes"<<endl;
            cout<<i<<endl;
            vector<int>v[i];
            int cnt=1;
            rep(j,i)REP(k,j+1,i){
                v[j].push_back(cnt);
                v[k].push_back(cnt);
                cnt++;
            }
            rep(j,i){
                cout<<v[j].size()<<" ";
                for(auto e:v[j])cout<<e<<" ";
                cout<<endl;
            }
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
