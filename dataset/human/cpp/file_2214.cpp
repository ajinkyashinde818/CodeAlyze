#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A[100000];
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];

    int negative = 0;
    for(int i=0; i<N; i++) if(A[i] < 0){
        negative++;
        A[i] *= -1;
    }

    sort(A, A+N);
    if(negative % 2 == 1) A[0] *= -1;

    int64_t ans = 0;
    for(int i=0; i<N; i++) ans += A[i];
    cout << ans << endl;
    return 0;
}
