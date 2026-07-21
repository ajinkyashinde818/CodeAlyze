#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {
    int n, r;
    cin >> n >> r;
    int ans;
    if(n>=10) ans=r;
    else ans=100*(10-n)+r;
    cout << ans << endl;
}
