#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    int a[100001];
    cin >> N;
    long long ans = 0;
    int mini = INT_MAX, cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            cnt++;
        }
        ans += abs(a[i]);
        mini = min(abs(a[i]),mini);
    }
    if(cnt % 2 == 1){
        ans -= 2*mini;
    }
    cout << ans << endl;
    return 0;
}
