#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 	int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for(int i=0;i<=N;i++){
        if(i % R != 0) continue;
        for(int j=0;j<=N;j++){
            if(j % G != 0) continue;
            int rest = N - i - j;
            if(rest < 0) continue;
            if(rest % B != 0) continue;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
