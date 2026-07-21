#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int MOD = 1000000007;

int main(void){
    int N, R; cin >> N >> R;
    
    if (N >= 10) cout << R << endl;
    else cout << R + 100 * (10 - N) << endl;
}
