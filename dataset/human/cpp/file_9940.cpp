#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
typedef long long ll;
int n=0;
string s;
ll a[26];
ll p=1e9+7;
int main(){
    //ios_base::sync_with_stdio(false);
    cout<<fixed<<setprecision(15);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        a[s[i]-'a']++;
    }
    ll ans=1;
    for(int i=0;i<26;i++){
        ans*=a[i]+1;
        ans%=p;
    }
    ans--;
    ans+=p;
    ans%=p;
    cout<<ans;
    return 0;
}
