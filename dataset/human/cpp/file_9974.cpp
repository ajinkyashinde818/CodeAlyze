#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long long MOD = 1000000007;
map<char,ll> m;
void solve(long long N, std::string S){
    for(auto&& i : S)
    {
        if(m.count(i)){
            m[i]++;
        }else{
            m[i]=1;
        }
    }
    ll ans=1;
    for(auto&& i : m)
    {
        ans*=i.second+1;
        ans%=MOD;
    }
    cout<<ans-1<<endl;
    
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
