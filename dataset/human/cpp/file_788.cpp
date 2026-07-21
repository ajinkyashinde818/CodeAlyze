#include <bits/stdc++.h>
using namespace std;


void solve(){

}

int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for(int i = 0; i * R <= N; i++){
        for(int j = 0; i * R + j * G <= N; j++){
            if ((N - i*R - j*G) % B == 0 ){
                ans++;
            }
        }
    }
    cout << ans << endl;

}
