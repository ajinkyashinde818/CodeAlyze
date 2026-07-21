#include<iostream>
#include<cassert>
#include<stdexcept>
#include<utility>
#include<functional>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<bitset>
#include<memory>
using namespace std;
using ll=long long;

const ll MOD=1e9+7;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll res=1;
    int cnt=0;
    for(int i=0;i<2*n;i++){
        bool isLef;
        if(s[i]=='W'){
            isLef=(i%2==0);
        }
        else{
            isLef=(i%2==1);
        }
        if(isLef){
            res=res*cnt%MOD;
            cnt--;
        }
        else{
            cnt++;
        }
    }
    if(cnt!=0) res=0;
    for(int i=0;i<n;i++) res=res*(i+1)%MOD;
    cout<<res<<endl;
    return 0;
}
