#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    int N; cin >> N;
    int nom = 0;
    int abmin = 1e9+5;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        if(a < 0) {
            a *= -1;
            nom++;
        }
        abmin = min(abmin, a);
        ans += a;
    }
    if(nom % 2 != 0) cout << ans - 2*abmin << endl;
    else cout << ans << endl;
    
}
