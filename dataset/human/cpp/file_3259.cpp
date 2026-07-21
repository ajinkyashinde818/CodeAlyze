#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, a;
    cin >> n;
    vector<ll> nums;
    for (ll i=0; i<n; i++) {
        cin >> a;
        nums.push_back(a);
    }
    ll tot = 0;
    ll minim = 1000000001;
    ll negs = 0;
    for (ll i=0; i<n; i++) {
        tot+=abs(nums[i]);
        minim = min(minim,abs(nums[i]));
        if (nums[i]<0) negs++;
    }
    if (negs%2==0) cout << tot;
    else cout << tot-2*minim;
    return 0;
}
