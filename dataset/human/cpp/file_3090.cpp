#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> A(N);
    int cntMinus=0;
    int min = 1e9;
    for(int i=0;i<N;i++){
        cin >> A[i];
        if( A[i] <= 0 )  cntMinus++;
        if( abs(A[i]) < abs(min) )  min = A[i];
    }

    long long ans=0;
    for(int i=0;i<N;i++){
        ans += abs(A[i]);
    }
    if( cntMinus % 2 == 1 ){
        ans -= abs(min) * 2;
    }

    cout << ans << endl;
}
