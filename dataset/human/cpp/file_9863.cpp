#include <bits/stdc++.h>
using namespace std;
int main (){
    long long N,ans=1;
    char x;
    cin >> N;
    vector<long long> v(26,0);
    
    for(long long i=0;i<N;i++){
        cin >> x;
        v.at(x-'a')++;
    }
    
    for(long long j=0;j<26;j++){
        ans *= v.at(j)+1;
        ans %= 1000000007;
    }

    ans--;
    
    ans %= 1000000007;
    cout << ans << endl;
}
