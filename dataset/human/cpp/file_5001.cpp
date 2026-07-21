#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define F first
#define S second
#define pb push_back
#define pii pair <int, int>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define reunique(a) (a).resize(unique(all(a)) - (a).begin())
#define ld long double
#define int long long

void SOLVE(){
    int n, r;
    cin >> n >> r;
    if (n >= 10){
        cout << r << '\n';
    }
    else{
        cout << r + (100 * (10 - n)) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int Q = 1;
    //cin >> Q;
    while (Q--){
        SOLVE();
    }

    return 0;
}
