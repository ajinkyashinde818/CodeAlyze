#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void solve(){
    int n, r;

    cin >> n >> r;

    if(n >= 10){
        cout << r << endl;
        return;
    }
    else
        cout << r + ((10 - n) * 100) << endl;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(16);
    
    solve();

    return 0;
}
