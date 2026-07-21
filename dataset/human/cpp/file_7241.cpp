#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long a[N],manag[N];

    for(int i=0;i<N;i++) manag[i] = 0;
    long long cnt = 0;

    for(int i=0;i<N;i++){
        cin >> a[i];

        cnt += a[i];
        manag[i] += cnt;
    }



    long long x, y;
    long long res = 10000000000;
    for(int i=0;i<N-1;i++){
        x = manag[i];
        y = cnt - manag[i];
        res = min(res, abs(x - y));
    }
    cout << res << endl;
}
