#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <cstdlib>
typedef long long ll;
const int MOD = 1e9+7;


#define REP(i, N) for (int i = 0; i < (N); i++)
#define REPP(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define VSORT(c) sort((c).begin(),(c).end())
#define SZ(x) ((int)(x).size())
//vvintを作る　マクロで　 #define vvint(N,M) vector<vector<int>>

using namespace std;


int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll tmp;
    ll mn = MOD, sum = 0;
    int minusCount = 0;
    bool zeroFlag = false;

    for(int i = 0; i < n;i++){
        cin >> tmp;
        if(tmp == 0){
            zeroFlag = true;
        }else { 
            mn = abs(min(abs(tmp),mn));
        }
        if(tmp < 0) minusCount++;
        sum += abs(tmp);
    }

    ll ans = 0;
    if(minusCount % 2 == 0 || zeroFlag){
        ans = sum;
    }else if(minusCount % 2 == 1){
        ans = sum-mn*2;
    }

    cout << ans << endl;

    

    return 0;
}
