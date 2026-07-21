#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int rn = n / r;
    int gn = n / g;
    int cnt = 0;
    for(int i = 0; i < rn + 1; i++){
        int res = n - r * i;
        if (res >= 0) {
            for (int j = 0; j < gn + 1; j++) {
                if((res - g * j) >= 0 && (res - g * j) % b == 0){
                    cnt++;
                }
                if(res - g * j < 0) break;
            }
        }
        else break;
    }
    cout << cnt << endl;

}
