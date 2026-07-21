#include <bits/stdc++.h>
using namespace std;
int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for (int i = 0; i <= N; ++i){
         for (int j = 0; j <= N; j++){
             int b = N - i * R - j * G;
             if (b >=0 ){
                 if (b % B == 0){
                     ans++;
                 }
             }
         }
    }
    cout << ans << endl;
}
