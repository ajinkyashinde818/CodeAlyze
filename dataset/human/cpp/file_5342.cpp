#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n, r;
    cin >> n >> r;
    int ans = 0;
    if(n >= 10) ans = r;
    else{
        ans = r + (10 - n) * 100;
    }
    cout << ans << endl;
    return 0;
}
