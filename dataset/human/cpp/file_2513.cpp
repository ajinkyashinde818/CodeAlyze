#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }

    int cnt = 0; //負の数が奇数のとき1になる

    for(int i=0; i<N; i++){
        if(A.at(i) < 0){
            cnt = 1 - cnt;
        }
    }
    long abs_sum=0;
    for(int i=0; i<N; i++){
            abs_sum = abs_sum + abs(A.at(i));
        }

    long ans;
    if(!cnt){
        ans = abs_sum;
    }
    else{ //絶対値のminを知りたい
    long abs_min=pow(10,9);
        for(int i=0; i<N; i++){
            abs_min = min( abs_min, abs(A.at(i)) );
        }
    ans = abs_sum - 2*abs_min;
    }
    cout << ans << endl;
}
