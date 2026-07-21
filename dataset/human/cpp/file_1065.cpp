#include <iostream> 
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <deque>  
#include <iomanip>

using namespace std;

using ll = long long;
const ll INF  = 1e9;
const ll MOD =  1e9 + 7;
#define rep(i, n) for(int i = 0; i < n; i++)
#define loop(i, a, n) for(int i = a; i < n; i++)
#define all(in) in.begin(), in.end()
int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for(int r = 0; r <= N; r++){
        for(int g = 0; g <= N; g++){
            if((N - r * R - g * G) % B == 0 && (N - r * R - g * G) >= 0){
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
