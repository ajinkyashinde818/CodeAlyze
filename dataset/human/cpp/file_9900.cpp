#include<iostream>
#include<map>
#include<string>
using namespace std;

static const int MOD=1000000007;
typedef long long ll;

int main(){
    int N;
    string s;
    cin >> N;
    cin >> s;
    map<char,int> m;
    ll ans=1;
    for(int i=0;i<N;i++){
        m[s[i]]++;
    }
    for(auto it=m.begin();it!=m.end();it++){
        ans*=(it->second+1);
        ans%=MOD;
    }
    cout << ans-1 << endl;
}
