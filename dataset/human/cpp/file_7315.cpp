#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a, v;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (i == 0) {
            a.push_back(m);
        } else {
            a.push_back(a.back() + m);
        }
        s += m;
    }
    
    for (int i = 0; i < n - 1; i++) {
        v.push_back(abs(a[i] - (s - a[i])));
    }
    sort(v.begin(), v.end());
    cout << v.front() << endl;
}
