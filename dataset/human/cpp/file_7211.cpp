#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;

int main(){
    int N; cin >> N;
    ll SUM=0, X=0, ans = 1e18;
    vector<int> A(N); for(int i = 0; i < N; i++) {cin >> A[i]; SUM += A[i];}
    for(int i = 0; i < N-1; i++){
        X += A[i];
        ll Y = SUM-X; 
        ans = min(ans, abs(X-Y));
    }
    cout << ans << endl;
}
