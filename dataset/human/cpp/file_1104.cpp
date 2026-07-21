#include <iostream>

using namespace std;

int main(void){
    int R, G, B, N, r, g, b, count;

    cin >> R >> G >> B >> N;

    count = 0;
    for(r = 0;R*r <= N;r++){
        for(g = 0;G*g <= N;g++){
            b = (N - R*r - G*g) / B;
            if(R*r + G*g + B*b == N && b > -1){
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
