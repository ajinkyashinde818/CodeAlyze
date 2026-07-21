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
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;



int main(){
    ll n;
    cin>>n;
    ll l=-1;
    for(ll i=2;;i++){
        if(i*(i-1)/2==n){l=i; break;}
        if(n<i*(i-1)/2){break;}
    }
    if(l==-1){cout<<"No"<<endl; return 0;}
    vector<vector<ll>> a(l);
    ll w=0;
    for(int i=0;i<l;i++){
        for(int t=i+1;t<l;t++){
            a[i].push_back(++w);
            a[t].push_back(w);
        }
    }
    cout<<"Yes"<<endl;
    cout<<l<<endl;
    for(int i=0;i<l;i++){
        cout<<a[i].size();
        for(int t=0;t<a[i].size();t++){
            cout<<" "<<a[i][t];
        }
        cout<<endl;
    }
    
    
    
    
    return 0;
}
