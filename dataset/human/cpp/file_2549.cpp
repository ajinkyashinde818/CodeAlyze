#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll; 
 
int N;
const int MAX_N = 100000;
ll A[MAX_N];


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int minus = 0;
    for (int i = 0; i < N; i++){
        if (A[i] <= 0){
            minus++;
        }
    }

    for (int i = 0; i < N; i++){
        if (A[i] < 0) A[i] = (-1) * A[i];
    }

    if (minus % 2 == 0){
        ll ans = 0;
        for (int i = 0; i < N; i++){
            ans += A[i];
        }
        cout << ans << endl;
    }
    else {
        sort(A, A+N);
        ll ans = (-1) * A[0];
        for (int i = 1; i < N; i++){
            ans += A[i];
        }
        cout << ans << endl;
    }

    
    return 0;    
}
