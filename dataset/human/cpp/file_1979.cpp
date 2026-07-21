#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll N, A[100010];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    
    ll minus = 0, m = 1e9, sum = 0;
    for (int i = 0; i < N; ++i){
        if (A[i] < 0) minus++;
        m = min(m, abs(A[i]));
        sum += abs(A[i]);
    }
    if (minus % 2 == 1){
        sum -= m * 2;
    }
    cout << sum << endl;
}
