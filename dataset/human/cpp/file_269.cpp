#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int r, g, b, n;

    cin >> r >> g >> b >> n;

    int cnt = 0;

    // x y

    for(int x = 0; x <= 3000; ++x){
        for(int y = 0; y <= 3000; ++y){
            int left = n - x * r - y * g;
            if(left >= 0 && left % b == 0)
                ++cnt;
        }
    }

    cout << cnt;


    return 0;
}
