#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    long long n, a, m, t = 0, x = 0;
    cin >> n;
    cin >> m;
    x += (m < 0);
    m = abs(m);
    t += m;
    for(int i = 1; i < n; i++){
        cin >> a;
        x += (a < 0);
        a = abs(a);
        t += a;
        m = min(m, a);
    }
    cout << (x % 2 == 0 ? t : t - 2*m) << '\n';
}
