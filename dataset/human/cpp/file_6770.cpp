#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main()
{
    int n; cin >> n;
    vi a(n), b(n), ind_a(n + 1, -1), sum(n + 1);
    int k = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ind_a[a[i]] = i;
        sum[a[i]]++;
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        if((!i || b[i] != b[i - 1]) && ind_a[b[i]] != -1){
            k = max(k, ind_a[b[i]] - i + 1);
        }
        sum[b[i]]++;
    }
    for(int i = 0; i <= n; ++i){
        if(sum[i] > n){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for(int i = n - k; i < n; ++i){
        cout << b[i] << " ";
    }
    for(int i = 0; i < n - k; ++i)
        cout << b[i] << " ";
    return 0;
}
