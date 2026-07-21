#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N; //整数の個数
    int cnt = 0; //負の数を数える
    ll smst = pow(10,9)+1; //絶対値が一番小さい数
    ll sum = 0; //整数の絶対値の合計
    
    cin >> N;

    for(int i=0; i<N; i++){
        ll a; cin >> a;
        if(a < 0){
            a = abs(a);
            cnt++;
        }

        smst = min(smst,a);
        sum += a;
    }

    if(cnt%2 == 1) sum -= 2*smst;

    cout << sum << endl;

}
