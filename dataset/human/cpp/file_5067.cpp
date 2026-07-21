#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, r, k;
    cin >> n>>r;
    if(n >= 10)
        k = r;
    else
        k = r+(100*(10 - n));
    cout <<k <<endl;

}
