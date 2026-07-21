//c++ 10 ** 7 の定数倍は普通に通るので，9 * 10 ** 6 も可能．
#include<iostream>
using namespace std;
int main(){
    int r, g, b, N;
    int a;
    int ans = 0;
    cin >> r >> g >> b>> N;
    for(int i = 0; i < N + 1; i++){
        for(int j = 0; j < N + 1; j++){
            if(N - r * i >= 0){
                a = N - r * i;
                if(a - g * j >= 0){
                    a -= g * j;
                    if(a % b == 0){
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans <<endl;
}
