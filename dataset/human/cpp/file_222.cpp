#include <iostream>
using namespace std;
int main(void){
    int R,G,B,n,ans = 0;
    cin >> R >> G >> B >> n;
    for(int r = 0;r <= 3000;r++){
        for(int g = 0;g <= 3000;g++){
            int tmp = (n - R*r -G*g);
            if(tmp%B == 0 && tmp >= 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
