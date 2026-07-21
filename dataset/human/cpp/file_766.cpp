#include <bits/stdc++.h>
using namespace std;

int R,G,B,n;
int main(){
    cin>>R>>G>>B>>n;
    int ans = 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            int now = R * i + G * j;
            if (now > n) continue;
            now = n - now;
            if (now % B == 0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
