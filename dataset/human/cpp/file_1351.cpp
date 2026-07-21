#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
#include<utility>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;

int main(){
    ll r, g, b, n, ans = 0;
    cin >> r >> g >> b >> n;
    for(int i = 0; i <= 3000; i++){
        if(r * i > n) break;
        for(int j = 0; j <= 3000; j++){
            if(r * i + g * j > n) break;
            if((n - (r * i + g * j)) % b == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
