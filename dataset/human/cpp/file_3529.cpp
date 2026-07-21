#include <iostream>
#include <numeric>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    long ans = 0;
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int mcount = 0;

    for(int i = 0; i < N; i++){
        if(A[i] < 0){
            mcount++;
        }
    }

    if(mcount % 2 == 0){
        for(int x : A){
            ans += abs(x);        
        }
    }

    int minvalue = 1000000000;
    int minflag = 0;
    
    if(mcount % 2 != 0){
        for(int i = 0; i < N; i++){
            if(abs(A[i]) < minvalue){
                minvalue = abs(A[i]);
                minflag = i;
            }
        }

        
        for(int i = 0; i < N; i++){
            if(i == minflag){
                ans = ans - abs(A[i]);
            }else{
                ans += abs(A[i]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
