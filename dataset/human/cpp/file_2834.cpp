#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    int64_t sgn = 1;
    bool zero = false; //zeroが存在するか
    for ( int64_t i = 0; i < N; ++i){
        cin >> A[i];
        if ( A[i] ==0 ) zero = true;
        else if ( A[i] < 0 ) sgn *= -1;
    }
    
    int64_t res = 0;
    if ( zero or sgn == 1){
        for ( int64_t i = 0; i < N; ++i){
            res = res + abs(A[i]);
        }
    } else {
        for ( int64_t i = 0; i < N; ++i){
            A[i] = abs(A[i]);
        }
        sort(A.begin(),A.end());
        for ( int64_t i = 0; i < N; ++i){
            if ( i == 0 ) res = res - A[i];
            else res = res + A[i];
        }
    }
    
    cout << res << endl;
    
    return 0;
}
