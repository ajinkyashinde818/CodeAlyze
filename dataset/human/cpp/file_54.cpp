#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    vector<int> v;
    v.push_back(r);
    v.push_back(g);
    v.push_back(b);
    sort(v.begin(), v.end(), greater<int>());
    long long cnt = 0;
    for (int i=n/v[0]; i>=0; i--) {
        for (int j=(n-i*v[0])/v[1]; j>=0; j--) {
            if ((n-i*v[0]-j*v[1])%v[2] == 0) cnt++;
        }
    }
    cout << cnt << endl;
}
