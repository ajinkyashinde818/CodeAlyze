#include<iostream>
using namespace std;

int main(){
    long N;
    long A[100002];
    long minabsA = 1e9+2;
    long long ans = 0;
    long minuscount = 0;

    cin >> N;
    for(long i=0;i<N;i++){
        cin >> A[i];
        minabsA = min(minabsA, abs(A[i]));
        ans += abs(A[i]);
        if(A[i] < 0){
            minuscount++;
        }
    }

    if(minuscount % 2 == 1){
        ans -= 2*minabsA;
    }

    cout << ans << endl;
    return 0;
}
