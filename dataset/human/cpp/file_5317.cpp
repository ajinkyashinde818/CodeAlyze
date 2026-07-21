#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);	
   
    int k, r, d=0;
    cin >> k >> r;
    if(k >= 10)
        cout << r;
    else
        cout << r+100*(10-k);
    return 0;
}
