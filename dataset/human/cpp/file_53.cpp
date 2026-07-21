#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) int((x).size())
#define OUT(x) cout << (x) << endl;
typedef long long ll;
typedef vector<int> V;
typedef vector<vector<int>> VV;
typedef pair<int, int> P;
typedef map<string, int> M;
typedef unordered_map<int, int> HM;
typedef set<int> S;
typedef queue<int> Q;

int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i=0; i<=3000; i++){
        for(int j=0; j<=3000; j++){
            int tmp = n-i*r-j*g;
            if(tmp >= 0 && tmp%b == 0) ans++;
        }
    }
    OUT(ans);
}
