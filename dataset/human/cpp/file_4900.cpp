#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
int main(){
    int n,r;cin >> n >> r;
    if(n>=10){
        cout << r << endl;
        return 0;
    }
    else{
        cout << r+(100*(10-n)) << endl;
        return 0;
    }
}
