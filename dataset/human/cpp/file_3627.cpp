#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    int neg=0, i_min=0;
    long sum=0;
    for(int i=0, x; i<N; i++){
        cin >> x;
        A[i] = abs(x);
        if(x < 0) neg++;
        if(A[i] < A[i_min]) i_min = i;
        sum += A[i];
    }
    if(neg%2 == 1){
        sum -= A[i_min] * 2;
    }

    cout << sum << endl;
}
