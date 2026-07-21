#include<bits/stdc++.h>
using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int r=0; r <= N/R+1; r++){
        for (int g=0; g <= N/G+1; g++){
            int nokori = N - r * R - g * G;
            if ((nokori >= 0) && (nokori % B == 0)){
                ans++;
            } 
        }
    }
    cout << ans << endl;
}
