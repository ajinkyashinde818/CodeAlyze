#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<queue>
#include<functional>
#include<iso646.h>
#include<bitset>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e10;
const ll MOD = 1e9 + 7;
const ll MAX_N = 1e5;

int main(){
    ll N;
    cin>>N;
    ll i, j;
    ll n = 1;
    ll fn = n;
    while(1){
        if(N == fn){
            cout<<"Yes"<<endl;
            break;
        }
        if(N < fn){
            cout<<"No"<<endl;
            return 0;
        }
        n++;
        fn += n;
        if(fn > MAX_N){
            cout<<"No"<<endl;
            return 0;
        }
    }
    ll nset = n + 1;
    vector<vll> S(nset);
    ll ssize = n;
    ll th_s = 0;
    ll th_e = 0;
    while(ssize > 0){
        for(i=1;i<=ssize;i++){
            S[th_s].push_back(th_e + i);
            S[th_s + i].push_back(th_e + i);
        }
        th_s++;
        th_e += ssize;
        ssize--;
    }
    cout<<nset<<endl;
    for(i=0;i<nset;i++){
        cout<<S[i].size()<<" ";
        for(auto e: S[i]) cout<<e<<" ";
        cout<<endl;
    }
    return 0;
}
