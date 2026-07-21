// Flipping Signs 
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll m=0;;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll mn=abs(a[0]);
    ll sum=0;
    for(int i=0; i<n; i++){
        if(a[i]<0){m++;}
        sum+=abs(a[i]);
        mn=min(abs(a[i]), mn);
    }
    if(m%2==0){
        cout << sum << endl;
        return 0;
    }
    else{
        cout << sum-(mn*2) << endl;
        return 0;
    }

}
