#include <iostream>
using namespace std;
int main(){
    int R, G, B, N, cnt=0;
    cin >> R >> G >> B >> N;
    for(int r=0; r<=N; r++){
        for(int g=0; N - r*R - g*G >= 0; g++){
            if( (N - r*R - g*G) % B == 0 ){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
