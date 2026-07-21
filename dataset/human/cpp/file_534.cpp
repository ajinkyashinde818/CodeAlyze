#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int count = 0;
    int rmax = n / r;
    int gmax = n / g;
    int bmax = n / b;
    for(int i = 0; i <= rmax; i++){
        for(int j = 0; j <= (n - r * i) / g; j++){
            if((n - r * i - g * j) % b == 0) count++;
        }
    }

    cout << count << endl;
}
