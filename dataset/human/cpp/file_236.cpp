#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            int a = N - R*i - G*j;
            if(a%B == 0 && a >= 0) ans++; 
        }
    }
    cout << ans << endl;
}
