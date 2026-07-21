#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> ans(n);
    for (int i = n / 2 + 1; i < n; i++)
        ans[i] = m;
    
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << " ";
    cout << ans[n - 1] << endl;
}
