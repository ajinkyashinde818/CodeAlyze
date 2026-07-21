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
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
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
    vector<ll> a(n);
    ll mns=0;
    ll sum=0;
    ll mi=E;
    for(auto &I:a){
        cin>>I;
        if(I<0){mns++;}
        sum+=abs(I);
        mi=min(mi,abs(I));
    }
    if(mns&1){cout<<sum-2*mi<<endl;}
    else{cout<<sum<<endl;}
    
    
    return 0;
}
