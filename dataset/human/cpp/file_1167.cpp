#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int R,G,B,N,ans=0;
    cin>>R>>G>>B>>N;
    for(int r=0; r<=N/R; r++) {
        for(int g=0; g<=N/G; g++) {
            int num = N - (R * r) - (G * g);
            if(num % B == 0 && num >= 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
