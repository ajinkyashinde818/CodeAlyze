#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int n;
int a[100005];
 
long long ans = 0;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int no_neg = 0;
    int nin = 1000000000;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        no_neg += (a[i] < 0);
        ans += abs(a[i]);
        nin = min(nin, abs(a[i]));
    }
 
    if(no_neg % 2) ans -= nin * 2LL;
    cout << ans;
}
