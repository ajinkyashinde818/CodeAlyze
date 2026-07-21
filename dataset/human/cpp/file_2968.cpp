#include <iostream>
#include <limits>

using namespace std;

int main(){
    long N;
    cin >> N;
    long sum = 0;
    bool bl_0 = false;
    long nk =0;
    long A[N];
    long min = numeric_limits<long>::max();
    long min_i = 0;
    for(long i=0;i<N;i++) A[i] = 0;
    for(long i=0;i<N;i++){
        cin >> A[i];
        if(A[i] < 0){
            A[i] = -A[i];
            nk++;
        }
        if(A[i] == 0) bl_0 = true;
        if(A[i] < min){
            min = A[i];
            min_i = i;
        }
        sum += A[i];
    }
    
    if(!bl_0){
        if(nk%2 != 0){
            sum -= 2*A[min_i];
        }
    }
    cout << sum << endl;
    return 0;
}
