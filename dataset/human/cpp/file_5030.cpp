#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
void chmin(int &a, int b) {if(a > b) a = b;}

const int mod = 1000000007;
const int inf = 1e9;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


int main(){
    int n,r;
    cin >> n >> r;
    if(n < 10)cout << r + 100 * (10-n);
    else cout << r;
}
