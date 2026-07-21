#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n, k;
    cin >> n >> k;
    if( n >= 10 ){
        cout << k << "\n";
    }else{
        n = 100*(10-n);
        cout << k+n << endl;
    }
    return 0;
}
