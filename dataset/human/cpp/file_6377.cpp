#include <iostream>
using namespace std;
typedef long long ll;
ll n,ans=1LL,MOD=1000000007,cnt;
string s;
ll f(ll n){
    if(n==1)return 1;
    return n*f(n-1)%MOD;
}
int main(void){
    cin>>n>>s;
    for(int i=0;i<2*n;i+=2){
        if(s[i]=='W')s[i]='B';
        else s[i]='W';
    }
    for(int i=0;i<n*2;i++){
        //cout<<s<<endl;
        //cout<<ans<<cnt<<endl;
        if(s[i]=='W')cnt++;
        else{
            ans*=cnt;
            ans%=MOD;
            cnt--;
        }
        //cout<<cnt<<endl;
        if(cnt==-1){
            cout<<0<<endl;
            return 0;
        }
    }
    if(cnt!=0)cout<<0<<endl;
    else cout<<ans*f(n)%MOD<<endl;
}
