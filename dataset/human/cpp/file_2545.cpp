#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N; cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    long long sum = 0;
    int minus = 0;
    long long mi = 1LL << 30;
    for(int i = 0; i < N; i++){
        if(A[i] < 0)minus++;
        sum += abs(A[i]);
        mi = min(mi, abs(A[i])); 
    }
    if(minus % 2 ==0)cout << sum << endl;
    else cout << sum - mi * 2 << endl;
}
