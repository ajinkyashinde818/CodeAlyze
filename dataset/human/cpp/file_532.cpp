#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


int main() {
    int R, G, B, N; cin >> R >> G >> B >> N;
    ll ans = 0;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            int k = (N - R * i - G * j)/B;
            if(R*i + G*j + B*k == N &&  k>=0 && k<=N) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
