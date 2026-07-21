#include <bits/stdc++.h>

using namespace std;


int main(){
    
    int N;
    cin >> N;
    vector<long int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    long int sum = 0;
    int zero = 0;
    long int mi = 1000000000;
    
    for (int i = 0; i < N-1; i++) {
        if (A[i] < 0) {
            A[i] = -1*A[i];
            sum += A[i];
            mi = min(mi, A[i]);
            A[i+1] = -1*A[i+1];
        }else if(A[i] == 0){
            zero = 1;
        }else{
            sum += A[i];
            
            mi = min(mi, A[i]);
        }
        
    }

    if (A[N-1] >= 0) {
        
        sum += A[N-1];
        
    }else{
        
        if (zero == 1) {
            sum -= A[N-1];
        }else{
            mi = min(mi, -A[N-1]);
            A[N-1] = -1*A[N-1];
            sum = sum + A[N-1] - 2*mi;
        }
        
    }
    
    
    
    cout << sum << endl;
    
}
