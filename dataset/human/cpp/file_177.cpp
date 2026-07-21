#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int answer = 0;

    for(int r = 0; r < int(N/R)+1; r++){
        for(int g = 0;g < int(N/G)+1;g++){
            if(r*R + g*G > N){
                break;
            }
            if((N - r*R - g*G)%B == 0){
                answer++;
            }
        }
    }
    cout << answer << endl;

    return 0;
}
