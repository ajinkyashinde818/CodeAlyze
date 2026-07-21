#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10, mod = 1e9 + 7;
char s[N];
int a[N],n;
int main(){
    scanf("%d%s",&n,s);
    for(int i=2*n-1;i>=0;i--){
        a[i] = (s[i]=='B')^((2*n-1-i)&1);
    }
//    for(int i=0;i<2*n;i++) cout<<a[i]; cout<<endl;
    int ans = 1, l = 0, r = 0;
    for(int i=2*n-1;i>=0;i--){
        if(a[i]==0){
            ans = 1ll * ans * max(r-l,0) % mod;
        }
        l += 1 - a[i], r += a[i];
    }
    if(l!=r) ans = 0;
    while(n){
        ans = 1ll * ans * n % mod;
        n--;
    }
    cout<<ans<<endl;
}
