#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
long long a[N];
long long ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    long long mini = 1e18;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(a[i] < 0){cnt++;a[i]=-a[i];}
        ans += a[i];
        mini = min(mini,a[i]);
    }
    cout << (cnt&1 ? ans - 2 * mini : ans) << "\n";


    return 0;
}
