#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    
    ll sum = 0;
    ll n_count = 0;
    ll minimum = 1000000001;
    ll a;
    for(ll i=0; i<n; i++){
        cin >> a;
        if(a > 0){
            sum += a;
            minimum = min(minimum, a);
        }else{
            sum -= a;
            ++n_count;
            minimum = min(minimum, -a);
        }
    }
        
    if(n_count % 2 == 0)
        cout << sum << endl;
    else
        cout << sum - 2 * minimum << endl;
    
    return 0;
}
