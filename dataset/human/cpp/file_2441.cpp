#include <iostream>

using namespace std;

const long INF = 10e+10;

int main(){
    int N;
    long A[100000];
    cin >> N;
    long cnt_minus = 0;
    long min_abs = INF;
    long abs_sum = 0;    
    for(int i = 0; i < N; i++){
        cin >> A[i];
        abs_sum += abs(A[i]);
        min_abs = min(min_abs, abs(A[i]));
        if(A[i] < 0){
            cnt_minus++;
        }
    }
    if(cnt_minus%2 == 0){
        cout << abs_sum << endl;
    }else{
        cout << abs_sum - 2*min_abs << endl;
    }
}
