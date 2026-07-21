#include<bits/stdc++.h>

using namespace std;

int main(void){
    int s = 0;
    long long ans = 0;
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        ans += abs(A[i]);
        if(A[i] < 0) s++;
        A[i] = abs(A[i]);
    }

    if(s % 2 == 1) ans -= 2 * (*min_element(A.begin(), A.end()));
    cout << ans << endl;



    return 0;
}
