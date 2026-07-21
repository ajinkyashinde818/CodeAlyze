#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    vector<long long> B(n + 1, 0);
    for(int i = 0; i < n + 1; i++){
        if(i > 0){
            B[i] += A[i - 1] + B[i - 1];
        }
    }

    long long mini = 1e18;
    for(int i = 0; i < n - 1; i++){
        mini = min(mini, abs(B[n] - B[i + 1] - B[i + 1]));
    }

    cout << mini << endl; 

    return 0;
}
