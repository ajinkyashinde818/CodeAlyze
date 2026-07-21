#include<iostream>
using namespace std;


int main(){
    int N;
    cin >> N;

    long long A[N];
    int cou = 0;
    int zero = 0;
    int min = 1000000000;
    int num = 0;
    for(int i = 0; i < N; i++){
        int re = 0;
        cin >> A[i];
        if(A[i] == 0){
            zero = 1;
            re = 0;
        }else if(A[i] < 0){
            cou++;
            re = -A[i];
        }else{
            re = A[i];
        }

        if(min > re){
            min = re;   
            num = i;     
        }
    }

    long long ans = 0;
    int ki = 0;
    ki = cou % 2;

    if(zero != 0 || ki == 0){
        for(int i = 0; i < N; i++){
            if(A[i] < 0){
                ans -= A[i];
            }else{
                ans += A[i];
            }
        }
    }else{
        for(int i = 0; i < N; i++){
            if(i == num){
                if(A[i] < 0){
                    ans += A[i];
                }else{
                    ans -= A[i];
                }
            }else{
                if(A[i] < 0){
                    ans -= A[i];
                }else{
                    ans += A[i];
                }
            }
        }
    }

    cout << ans <<endl;
}
