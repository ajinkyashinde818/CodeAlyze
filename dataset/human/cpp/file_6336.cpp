#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long const mod = 1e9+7;
int main(void){
    int n;
    string s;
    cin >> n >> s;
    int lft = 0;
    long long ans = 1;
    for(int i=0;i<n*2;i++){
        if((s[i] == 'B') == (i%2 == 1)){
            if(lft == 0){
                ans = 0;
                break;
            }
            ans *= lft--;
            ans %= mod;
        }else{
            lft++;
        }
    }
    if(lft != 0) ans = 0;
    else for(int i=2;i<=n;i++) ans = ans*i%mod;
    cout << ans << endl;
}
