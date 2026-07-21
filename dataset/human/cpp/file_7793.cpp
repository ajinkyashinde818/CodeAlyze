#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        sum += A[i];
        if(i != 0) A[i] += A[i-1];
    }
    long long ret = 1L<<60;
    for(int i = 0; i < N-1; ++i){
        ret = min(ret, abs(A[i] - (sum - A[i])));
    }
    cout << ret << '\n';
    return 0;
}
