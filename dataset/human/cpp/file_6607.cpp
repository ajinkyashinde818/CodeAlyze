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
#include <cassert>
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
    int N; cin >> N;
    string S; cin >> S;

    for(int i=0; i<2*N; i++){
        if(i%2==0){
            if(S[i]=='B') S[i] = 'W';
            else S[i] = 'B';
        }
    }
    
    vector<int> L(2*N+1), R(2*N+1);
    int cR = 0;
    int cL = 0;
    for(int i=0; i<2*N; i++){
        if(S[i]=='B'){
            cR++;
            R[i+1] = R[i] + 1;
            L[i+1] = L[i];
        }else{
            cL++;
            R[i+1] = R[i];
            L[i+1] = L[i] + 1;
        }
    }
    
    if(cR!=cL){
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = 1;
    for(int i=0; i<2*N; i++){
        if(S[i]=='B') ans = ans * (L[i] - R[i]) % MOD;
    }
    
    for(int i=1; i<=N; i++){
        ans = ans * i % MOD;
    }
    
    cout << ans << endl;
    return 0;
    
}
