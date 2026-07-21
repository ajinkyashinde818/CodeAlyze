#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, sum[1010], x;
bool jud = false;
vector<ll> ans[1010];
int main(void){
    // Your code here!
    cin >> n;
    for (ll i = 0; i < 1000; i++) sum[i + 1] = sum[i] + i + 1;
    for (ll i = 1; i <= 1000; i++){
        if (sum[i] == n){
            jud = true;
            x = i;
            break;
        }
    }
    if (jud){
        cout << "Yes" << endl;
        cout << x + 1 << endl;
        for (ll i = 2; i <= x + 1; i++){
            for (ll j = 1; j < i; j++){
                ans[i].push_back(sum[i - 2] + j);
                ans[j].push_back(sum[i - 2] + j);
            }
        }
        for (ll i = 1; i <= x + 1; i++){
            cout << x << ' ';
            for (ll j = 0; j < x - 1; j++){
                cout << ans[i][j] << ' ';
            }
            cout << ans[i][x - 1] << endl;
        }
    } else {
        cout << "No" << endl;
    }
}
