#include <bits/stdc++.h>

int main() {
    using namespace std;
    constexpr unsigned long max_size = 10000;
    unsigned long N, M;
    cin >> N >> M;
    bitset<max_size> A, B, mask;
    for(unsigned long i = 0; i < N; ++i){
        string s;
        cin >> s;
        for(unsigned long j = 0; j < N; ++j)A[i * 100 + j] = s[j] == '#';
    }
    for(unsigned long i = 0; i < M; ++i){
        string s;
        cin >> s;
        for(unsigned long j = 0; j < M; ++j){
            mask[i * 100 + j] = true;
            B[i * 100 + j] = s[j] == '#';
        }
    }
    for(unsigned long i = 0; i < 100 * N; ++i)if((A >> i & mask) == B)return 0 & puts("Yes");
    puts("No");
    return 0;
}
