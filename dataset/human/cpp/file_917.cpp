#include <bits/stdc++.h>
using namespace std;

int main(void){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int b = 0;
    int cnt = 0;
    for(int r = 0; r <= N; r++){
        for(int g = 0; g <= N; g++){
            b = N - r*R - g*G;
            if(b%B == 0 && b >= 0) cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
