#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
using namespace std;
typedef long long ll;
typedef long long int llint;
typedef pair<ll, ll> pa;
#define MM 1000000000
#define MOD MM+7
#define MAX 101000
#define MAP 110
#define initial_value -1
#define MAX_T 1001
#define Pair pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912
const long double PI = acos(-1);
const ll DEP = 1e18;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
void init(int a[100001]){
    for(int i = 0; i < 100001; i++){
        a[i] = MM;
    }
}
int main(){
    int cnt = 0;
    int r,g,b,n; cin >> r >> g >> b >> n;
    for(int i = 0; i*r <= 3000; i++){
        for(int j = 0; i*r + j*g <= 3000; j++){
            int tmp = n - i*r - j*g;
            if(tmp % b == 0 && tmp >= 0) cnt++;
        }
    }
    cout << cnt << endl;
}
