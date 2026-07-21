#include <bits/stdc++.h>

int main() {
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    unsigned long N;
    cin >> N;
    deque<bool> A(2 * N);
    {
        deque<bool> B(2 * N);
        string S;
        cin >> S;
        for(unsigned long i = 0; i < 2 * N; ++i)B[i] = S[i] & 1;
        A[0] = B[0];
        bool s = true;
        for(unsigned long i = 1; i < 2 * N; ++i){
            A[i] = B[i] ^ s;
            s ^= 1;
        }
    }
    if(accumulate(A.begin(), A.end(), 0UL) != N)return 0 & puts("0");
    unsigned long ans{1}, amari{0};
    for(unsigned long i = 1; i <= N; ++i)(ans *= i) %= MOD;
    for(const auto& i : A){
        if(i){
            (ans *= amari) %= MOD;
            if(amari)--amari;
            else return 0 & puts("0");
        }else ++amari;
    }
    cout << ans << endl;
    return 0;
}
