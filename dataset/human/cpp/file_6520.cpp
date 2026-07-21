#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

char s[200005];

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    ll ans = 1, num = 0;
    for(int i = 1;i<=n*2;i++) {
        if(s[i]=='W') {
            if(i&1) {
                ans = ans*num%mod;
                if(--num<0) {
                    cout<<0<<'\n'; return 0;
                }
            } else {
                num++;
            }
        } else  {
            if(i&1) {
                num++;
            } else {
                ans = ans*num%mod;
                if(--num<0) {
                    cout<<0<<'\n'; return 0;
                }
            }
        }
    }
    if(num) {
        cout<<0<<'\n'; return 0;
    }
    for(int i = 1;i<=n;i++) ans = ans * i % mod;
    printf("%I64d\n",ans);
    return 0;
}
