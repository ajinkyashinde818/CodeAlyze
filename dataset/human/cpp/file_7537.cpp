#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    int N;cin>>N;
    //S[i]:a_1からa_iまでの和
    ll S[200010];
    S[0]=0;
    ll a;
    for(int i=1;i<=N;i++){
        cin>>a;
        S[i]=S[i-1]+a;
    }
    ll x,y,ans=pow(10,18);
    for(int i=1;i<=N-1;i++){
        x=S[i];y=S[N]-x;
        ans=min(ans,abs(x-y));
    }
    cout<<ans<<endl;
    return 0;
}
