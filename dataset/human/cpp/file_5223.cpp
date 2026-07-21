#include<bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr int mo = 1e9+7;
constexpr int inf = 1<<30;
constexpr ll infl = 1ll<<60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n,r;
    cin>>n>>r;
    
    if(n >= 10) cout << r << endl;
    else cout << 100*(10 - n) + r << endl;
    return 0;
}
