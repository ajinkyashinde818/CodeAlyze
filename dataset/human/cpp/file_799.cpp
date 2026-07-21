#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <cctype>
#include <fstream>
#include <cstring>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 2000000000
#define LINF 9000000000000000000
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define du(x) cout<<#x<<'='<<x<<endl
#define du2(x,y) cout<<#x<<'='<<x<<' '<<#y<<'='<<y<<'\n'<<endl
#define du3(x,y,z) cout<<#x<<'='<<x<<' '<<#y<<'='<<y<<' '<<#z<<'='<<z<<'\n'<<endl
#define darr(arr,n) rep(i,(n-arr)){cout<<*(arr+i)<<' ';}cout<<endl
#define ddarr(arr,a,b) rep(i,a){rep(j,b){cout<<*(arr+i*b+j)<<' ';}cout<<endl;}
#define ddd ifstream in("Text.txt");cin.rdbuf(in.rdbuf());


int main() {
    int R, G, B, N;

    cin >> R >> G >> B >> N;


    int ans = 0;
    rep(r, N+1) {
        rep(g, N+1) {
            if ((N - (r * R + g * G)) < 0)continue;
            if ((N - (r * R + g * G)) % B == 0) {
                ans++;
            }

        }

    }
    cout << ans << endl;

}
