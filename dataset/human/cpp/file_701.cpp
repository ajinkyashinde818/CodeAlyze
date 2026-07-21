#include <bits/stdc++.h>
using namespace std;

int main() {
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans=0;
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
            int v=R*i+G*j;
            if(N>=v&&(N-v)%B==0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
