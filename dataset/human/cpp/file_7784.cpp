#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    long long S,A;
    S = A = 0;
    vector<long long> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(i != N-1) S += a[i];
        else A = a[N-1];
    }
    reverse(a.begin(),a.end());
    long long Min = abs(S-A);
    for(int i = 1; i < N-1; i++){
        S -= a[i];
        A += a[i];
        Min = min(Min,abs(S-A));
    }
    cout << Min << endl;
}
