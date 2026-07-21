#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF =ll(1e18)+5;

int main() {
    ll N;
    cin >> N;
    ll minus =0;
    ll minV = INF;
    ll sum =0;
    for(int i=0;i<N;i++){
        ll A;
        cin >> A;
        if(A<0){
            minus++;
        }
        sum += abs(A);
        minV = min(minV,abs(A));
    }
    if(minus%2==1){
        sum -= (minV*2);
    }
    cout <<sum <<endl;

    return 0;
}
