#include <iostream>
#include <algorithm>
using namespace std;

int R, G, B, N;
int main(){
    cin >> R >> G >> B >> N;
    int cnt = 0;
    for (int r = 0; (r <= N); r++){
        for (int g = 0; (g <= N - r); g++){
            int Bb = N - G * g - R * r;
            if (Bb % B == 0){
                int b = Bb / B;
                if (b < 0){
                    continue;
                }
                else{
                    // cout << r << " " << g << " " << b << endl;
                    cnt ++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
