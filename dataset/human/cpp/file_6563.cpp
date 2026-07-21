#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    for(int i=0;i<2*n;i++){
        if(i%2==0){
            if(s[i]=='B')s[i]='W';
            else s[i]='B';
        }
    }
    ll ans=1;
    ll now=0;
    for(int i=0;i<2*n;i++){
        if(s[i]=='W')now++;
        else{
            if(now==0){
                cout << 0 << endl;
                return 0;
            }
            (ans*=now)%=mod;
            now--;
        }
    }
    if(now){
        cout << 0 << endl;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        (ans*=i)%=mod;
    }
    cout << ans << endl;
}
