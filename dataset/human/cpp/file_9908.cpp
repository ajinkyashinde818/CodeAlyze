#include <bits/stdc++.h>
using namespace std;

long long modplus(long long &a,long long &b){
    a=a%1000000007;
    b=b%1000000007;
    a=(a+b)%1000000007;
    return (a+b)%1000000007;
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> alphacnt(26,0);
    long long ans=0;
    for(auto c:s){
        long long t=1;
        for (int i = 0; i < 26; ++i) {
            if(c-'a'==i)continue;
            else {
                t=t*(alphacnt[i]+1);
                t=t%1000000007;
            }
        }
        ++alphacnt[c-'a'];
        modplus(ans,t);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
