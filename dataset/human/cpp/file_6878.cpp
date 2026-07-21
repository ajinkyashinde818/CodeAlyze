#include<bits/stdc++.h>
using namespace std;
int n, a[200005], b[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    reverse(b, b + n);

    int l = 0, r = n - 1;
    while (l < n && a[l] != b[l]) l++;
    while (r >= 0 && a[r] != b[r]) r--;

    int i, j;
    for (i = l, j = 0; i <= r && j < n; j++) {
        if (a[j] != b[i] && b[j] != b[i]) {
            swap(b[j], b[i]);
            i++;
        }
    }

    if (l > r || i == r + 1) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i == n - 1];
        }
    }
    else cout << "No\n";

    return 0;
}
