#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, N, n, i, j, k;
    cin >> R >> G >> B >> N;
    if(R == 1 && G == 1 && B == 1){
        cout << (N + 1) * (N + 2) / 2 << endl;
    }
    else{
        n = 0;
        i = 0;
        while(R * i < N + 1){
            j = 0;
            while(R * i + G * j < N + 1){
                k = 0;
                while(R * i + G * j + B * k < N + 1){
                    if(R * i + G * j + B * k == N){
                        n++;
                    }
                    k++;
                }
            j++;
            }
        i++;
        }
        cout << n << endl;
    }
  
}
