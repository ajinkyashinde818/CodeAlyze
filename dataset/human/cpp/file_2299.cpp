#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n;cin >> n;
    vector<ll> a(n);
    int mcnt=0;
    bool zero=false;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==0) zero=true;
        if(a[i]<0) mcnt++;
    }
    ll sum=0;
    vector<ll> pa(n);
    for(int i=0;i<n;i++){
        if(a[i]<0){
            sum+=-a[i];
            pa[i]=-a[i];
        }
        else{
            sum+=a[i];
            pa[i]=a[i];
        }
    }
    sort(pa.begin(),pa.end());
    ll mn=pa[0];
    if(mcnt%2==0) cout << sum << endl;
    else{
        cout << sum-2*mn << endl;
    }
    return 0;
}
