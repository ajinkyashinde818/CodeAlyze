#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    long long sum = 0;
    vector<long long>A(N,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    
    long long sum1 = 0;
    long long ans = 1e18;
    for (int i = 0; i < N; i++) {
        sum1 += A[i];
        if (i+1<N) {
            ans = min(ans, abs(sum - 2*sum1));
        }
    }
    cout << ans << endl;
}
