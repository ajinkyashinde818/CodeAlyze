#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
//void chmin(int &a, int b) { if (a > b) a = b; }
//void chmax(int &a, int b) { if (a < b) a = b; }

const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    int n,r;
    cin >> n >> r;
    if(n >= 10){
        cout << r << endl;
    }else{
        cout << r+100*(10-n) << endl;
    }
    return 0;
}
