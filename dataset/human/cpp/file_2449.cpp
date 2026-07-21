#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 

int  A(int x){
    if(x>=0)return x;
    else return -x;
}



int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n);
    bool flag = false;
    int num = 0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0)flag = true;
        if(a[i]<0)num++;
    }
    ll sum = 0;
    ll mi = (ll)INF;
    for(ll i=0;i<n;i++){
        ll x = A(a[i]);
        sum+=x;
        mi = min(mi,x);
    }
    if(flag)cout<<sum<<endl;
    else{
        if(num%2==0)cout<<sum<<endl;
        else{
            cout<<sum-2*mi<<endl;
        }
    }
    return 0;
}
