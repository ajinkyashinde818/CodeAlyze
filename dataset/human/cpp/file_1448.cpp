#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#define ll long long
#define INF 1e+7
#define MOD 1000000007
using namespace std;

int main(){
    ll N;
    cin >> N;
    
    if(N==1){
        cout<<"Yes"<<endl;
        cout<<2<<endl;
        cout<<"1 1"<<endl;
        cout<<"1 1"<<endl;
        return 0;
        return 0;
    }
    
    ll k=1;
    int ans=0;
    for(; k<=N; k++){
        if(k*(k+1) == N*2){
            ans=1;
            break;
        }
    }
    
    if(ans==0){
        cout<<"No"<<endl;
        return 0;
    }
    
    cout<<"Yes"<<endl;

    vector<ll> S[1000];
    ll l[1000]={};
    for(int i=1; i<=k; i++){
        S[1].push_back(i);
        l[1]++;
    }
    
    for(int i=2; i<=k+1; i++){
        S[i].push_back(i-1);
        l[i]++;
    }
    
    for(ll i=3; i<=k+1; i++){
        ll num=k+ (i-3)*(i-2)/2 +1 -2;
        for(ll t=2; t<=i-1; t++){

            S[i].push_back(num+t);
            l[i]++;

            S[t].push_back(num+t);
            l[t]++;
        }
    }


    cout<<k+1<<endl;
    for(ll i=1; i<=k+1; i++){
        cout<<l[i];
        for(ll s=0; s<l[i]; s++){
            cout<<" "<<S[i][s];
        }
        cout<<endl;
    }

    return 0;
}
