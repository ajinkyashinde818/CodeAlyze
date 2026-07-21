#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    int minus_count = 0;
    long result = 0;
    
    cin >> N;
    
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] < 0) {
            minus_count++;
        }
    }
    
    if ((minus_count % 2) == 0) {
        for (int i = 0; i < A.size(); i++) {
            A[i] = abs(A[i]);
        }
    } else {
        for (int i = 0; i < A.size(); i++) {
            A[i] = abs(A[i]);
        }
        sort(A.begin(), A.end());
        A[0] = -A[0];
    }
    
    for (int i = 0; i < A.size(); i++) {
        result += A[i];
    }
    
    cout << result << endl;
    
    return 0;
}
