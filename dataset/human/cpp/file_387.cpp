#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int main(){

    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;

    for(int i = 0; i <= 3000; i++){
        int tempSum1 = R * i;
        for(int j = 0; j <= 3000; j++){
            int tempSum2 = tempSum1 + G * j;
            if((N - tempSum2) >= 0 && (N - tempSum2) % B == 0){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
