#include <bits/stdc++.h>

using namespace std;
using lint = long long;
//typedef long long lint;

int main(void)
{
    int N;
    cin >> N;
    vector<lint> A(N);

    bool zero = false;
    lint mainus_cnt = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    lint absmin = abs(A[0]);
    lint sum = 0;
    for(int i = 0; i < N; i++){
        sum += abs(A[i]);
        if(A[i] == 0){
            zero = true;
        }
        if(A[i] < 0){
            mainus_cnt++;
        }
        if(absmin > abs(A[i])){
            absmin = abs(A[i]);
        }
    }

    if(zero){
        cout << sum << endl;
    }else if(mainus_cnt % 2 == 0){
        cout << sum << endl;
    }else{
        cout << sum - 2 * absmin << endl;
    }

}
