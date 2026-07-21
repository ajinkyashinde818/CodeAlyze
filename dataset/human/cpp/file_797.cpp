#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}

int R, G, B, n;

int main(){
    cin >> R >> G >> B >> n;
    int ans = 0;
    for(int r = 0; r <= n; r++){
        for(int g = 0; g <= n; g++){
            int x = n-r*R-g*G;
            if(x >= 0 && x%B == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
