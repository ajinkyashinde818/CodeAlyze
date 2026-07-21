#include <bits/stdc++.h>
using namespace std;

int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int kumi = 0;
    for (int r = 0;r <= N/R;r++){
        for (int g = 0;g <= (N-r*R)/G;g++){
            if ( (N - r*R - g*G)%B == 0){
                kumi++;
            }
        }
    }
    cout << kumi <<endl;
}
