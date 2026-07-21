#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    
    int cnt = 0;
    for(int i = 0; i <= 3000; i++){
        for(int j = 0; j <= 3000; j++){
            if((N-i*R-j*G) % B == 0 && (N-i*R-j*G) / B >= 0){
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;
}
