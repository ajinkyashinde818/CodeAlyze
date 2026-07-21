#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn] , b[maxn];
queue<int> Q;
int main()
{
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++) cin >> b[i];
    reverse(b + 1 , b + 1 + n);
    int l = -1;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] != b[i]) continue;
        l = i;
        break;
    }
    if (l == -1){
        cout << "Yes" << endl;
        for (int i = 1 ; i <= n ; i++) cout << b[i] << " ";
        cout << endl;
        return 0;
    }
    int r = -1;
    for (int i = n ; i >= 1 ; i --){
        if (a[i] != b[i]) continue;
        r = i;
        break;
    }
    for (int i = 1 ; i <= n ; i++){
        if (b[i] == b[l] || a[i] == b[l]) continue;
        Q.push(i);
    }
    if (r - l + 1 > (int)Q.size()) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = l ; i <= r ; i++){
        int t = Q.front();Q.pop();
        swap(b[t],b[i]);
    }
    cout << "Yes" << endl;
    for (int i = 1 ; i <= n ; i++) cout << b[i] << " ";
    cout << endl;
    return 0;
}
