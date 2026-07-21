#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;

void Main(){
    int N;
    scanf("%d", &N);
    vector<long long> A(N);
    vector<long long> sum(N, 0);
    for(int i = 0; i < N; i++){
        scanf("%lld", &A[i]);
        if(i == 0)sum[i] = A[i];
        else sum[i] = sum[i - 1] + A[i];
    }
    
    long long ans = INF;
    for(int i = 0; i < N - 1; i++){
        long long snuke = sum[i];
        long long racc = sum[N - 1] - sum[i];
        if(ans > abs(snuke - racc)) ans = abs(snuke - racc);
    }
    
    printf("%lld\n", ans);
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
}
