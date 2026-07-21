#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long A[N];
    long long minus = 0;
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] < 0) minus++;
        A[i] = abs(A[i]);
        ans += A[i];
    }
    if(minus % 2 == 1) cout << ans - *min_element(A, A + N) * 2 << endl;
    else cout << ans << endl;
}
