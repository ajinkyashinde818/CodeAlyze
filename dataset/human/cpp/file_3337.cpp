#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long A[N];
    long long sum = 0;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < N - 1; i++){
        if(A[i] < 0){
            A[i] *= -1;
            A[i+1] *= -1;
        }
    }

    if(A[N-1] >= 0){
        for(int i = 0; i < N; i++){
            sum += A[i];
        }
    }

    else{
        A[N-1] = -A[N-1];
        long long m = A[0];
        for(int i = 0; i < N; i++){
            m = min(m, A[i]);
            sum += A[i];
        } 
        sum -= 2 * m;
    }

    cout << sum << endl;
}
