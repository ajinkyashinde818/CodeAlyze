#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
vector<int> dy = {0,0,1,-1};
vector<int> dx = {1,-1,0,0};

int main(void){
    int R,G,B,N;
    int ans = 0;
    cin >> R >> G >> B >> N;
    for(int r = 0; r <= N; r++){
        for(int g = 0; g <= N; g++){
            if(r * R + g * G <= N && !((N - r * R - g * G) % B)){
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}
