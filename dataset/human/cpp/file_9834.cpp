#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <utility>
#include <functional>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;
int main()
{
    int n; cin>>n;
    string s; cin>>s;
    ll ct[26]={};
    for(int i=0; i<n; i++){
        ct[s[i]-'a']++;
    }
    ll ans=1;
    for(int i=0; i<26; i++){
        ans=ans*(ct[i]+1)%MOD;
    }
    ans=(ans+MOD-1)%MOD;
    cout<<ans<<endl;
    return 0;
}
