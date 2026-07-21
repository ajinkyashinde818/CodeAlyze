#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    
    int x=0;
    for(int r=0; r <= N; r++) {
        if(N-r*R < 0) break;
        for(int g=0; g <= N; g++) {
            if(N-r*R-g*G < 0) break;
            if((N-r*R-g*G)%B == 0) x++;
        }
    }
    cout << x << endl;
}
