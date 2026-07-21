#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll ct=0;
    ll mi=1LL<<60;
    ll ans=0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(A[i]<0) ct++;
        mi = min(mi,llabs(A[i]));
        ans+=llabs(A[i]);
    }
    cout << (ct&1 ? ans-2*mi : ans) << endl;

    return 0;
}
