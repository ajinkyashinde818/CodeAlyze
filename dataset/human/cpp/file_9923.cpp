#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1000000007;
ll ans,cnt[300];
char s[1234567];
int main(){
    int n; cin >> n;
    cin >> s;
    for (int i=0;i<n;i++) cnt[s[i]-'a']++;
    ans=1;
    for (int i=0;i<26;i++) ans=ans*(cnt[i]+1)%M;
    printf("%lld\n",(ans+M-1)%M);
    return 0;
}
