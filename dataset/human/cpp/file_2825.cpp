#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, minn=INT_MAX, neg=0,x ;
    cin >> n;
    ll sum = 0;
    for(int i=0; i<n; ++i){
        cin >> x;
        if(x < 0 ) ++neg;
        sum += abs(x);
        minn = min(minn, abs(x));
    }
    if(neg & 1){
        cout << sum - 2*minn << "\n";
    }
    else{
        cout << sum << "\n";
    }
}
