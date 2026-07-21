#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int count = 0;

    int r = N / R + 1;
    int g = N / G + 1;
    int b = N / B + 1;
    for(int i = 0; i < r; i++){
        int sum = i * R;
        for(int j = 0; j < g; j++){
            int sum_sub = sum;
            sum_sub += j*G;
            if((N -sum_sub) >= 0 && (N -sum_sub) % B == 0){
                count += 1;
            }
        }
    }
    cout << count << endl;
}
