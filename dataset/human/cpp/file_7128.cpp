#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    long long N;
    cin >> N;
    long long A[N];
    long long B[N];
    long long sums=0;

    for(int i=0;i<N;i++){
        cin >> A[i];
        if(i==0){
            B[i] = A[i];
        }
        else{
            B[i] = B[i-1] + A[i];
        }
        sums = sums + A[i];
    }

    long long mins = 0;
    long long diffs = abs(B[mins] - (sums - B[mins]));


    for(int i=1;i<N-1;i++){
        if(diffs > abs(B[i] - (sums - B[i]))){
            diffs = abs(B[i] - (sums - B[i]));
            mins = i;
        }
    }
    cout << abs(B[mins] - (sums - B[mins])) << endl;
    return 0;

}
