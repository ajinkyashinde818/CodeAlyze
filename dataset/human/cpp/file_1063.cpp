#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, N;
    int i, j, K, ans;
    cin >> R >> G >> B >> N;
    for(i=0;i<3001;i++) {
        for(j=0;j<3001;j++) {
            K = N-(R*i+G*j);
            if(K>-1 && K%B == 0){
                ans +=1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
