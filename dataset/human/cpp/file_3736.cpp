#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;

int main(){
    int N;
    scanf("%d", &N);
    vector<long long> A(N);
    
    long long ans = 0;
    long long mi = 0;
    for(int i = 0; i < N; i++){
        scanf("%lld", &A[i]);
        if(A[i] < 0){
            mi++;
            A[i] *= -1;
        }
        ans += A[i];
    }
    sort(A.begin(), A.end());
    if(mi % 2 == 1)ans -= A[0] * 2;
    
    printf("%lld\n", ans);
}
