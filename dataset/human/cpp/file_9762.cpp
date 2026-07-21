#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll numC[26];
    for(int i=0;i<26;i++){
        numC[i]=0;
    }
    for(int i=0;i<s.size();i++){
        numC[s[i]-'a']++;
    }
    ll ans=1;
    for(int i=0;i<26;i++){
        ans=ans*(numC[i]+1)%mod;
    }
    cout << ans-1 << endl;
}
