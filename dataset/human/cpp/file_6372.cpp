#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    int n;
    cin>>n;
    cin>>s;
    long long ans=1,cnt=0,temp=0,mod=1000000007;
    if(s[0]=='W'||s[s.length()-1]=='W'){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.length();i++){
        if((cnt&1)^(s[i]=='B')) cnt++;
        else{
            ans=ans*cnt%mod;
            cnt--;
            temp++;
        }
    }
    for(int i=1;i<=n;i++){
        ans=ans*i%mod;
    }
    if(temp==n) cout<<ans;
    else cout<<0;
}
