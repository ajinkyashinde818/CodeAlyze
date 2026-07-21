#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b, n, i, j, c = 0;
    cin >> r >> g >> b >> n;
    for(i=0; i<=n/r; i++){
        for(j=0; j<=(n-r*i)/g; j++){
            if((n-r*i-g*j) >= 0 && (n-r*i-g*j)%b == 0){
                c++;
            }
        }
    }
    cout << c;
    return 0;
}
