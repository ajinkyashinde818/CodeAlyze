#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int R, G, B, N;
    cin >> R >> G >> B >>N;

    int cnt = 0;

    for (int i = 0; i <= N / R; i++){
        for (int j = 0; j <= N / G; j++){
            int k = N - R * i - G * j;
            if (k >= 0 && k % B == 0){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
